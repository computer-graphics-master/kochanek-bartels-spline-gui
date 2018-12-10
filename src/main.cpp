/*
	Based on NanoGUI src/example3.cpp.

	NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
	The widget drawing code is based on the NanoVG demo application
	by Mikko Mononen.
*/

#include <algorithm>
#include <iostream>

#if defined(NANOGUI_GLAD)
#if defined(NANOGUI_SHARED) && !defined(GLAD_GLAPI_EXPORT)
#define GLAD_GLAPI_EXPORT
#endif

#include <glad/glad.h>
#else
#if defined(__APPLE__)
#define GLFW_INCLUDE_GLCOREARB
#else
#define GL_GLEXT_PROTOTYPES
#endif
#endif

#include <GLFW/glfw3.h>
#include <nanogui/nanogui.h>

#include "bevgrafmath2017.h"


const int CONTEXT_VERSION_MAJOR = 3;
const int CONTEXT_VERSION_MINOR = 0;

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;

const char *APPLICATION_TITLE = "Kochanek-Bartels Spline";


nanogui::Screen *screen = nullptr;

const int MINIMUM_NUMBER_OF_CONTROL_POINTS = 4;
const float CLICK_THRESHOLD = 100.0f;

const float PARAMETER_DELTA = 0.05f;

std::vector<vec2> controlPoints;

float tension = 0.0f;
float bias = 0.0f;
float continuity = 0.0f;

bool isDrawControlPolygon = true;
bool isDrawControlPoints = true;

vec2 *draggedControlPoint = nullptr;

GLFWwindow *createWindow();
void setupInputCallbacks(GLFWwindow * const window);

mat4 calculateCoefficientMatrix(const float tension, const float bias, const float continuity);

void drawCurve(const mat4& coefficientMatrix, const std::vector<vec2>& controlPoints);
void drawSegment(const size_t segmentIndex, const mat4& coefficientMatrix, const std::vector<vec2>& controlPoints);
void drawControlPolygon(const std::vector<vec2>& controlPoints);
void drawControlPoints(const std::vector<vec2>& controlPoints);

void onMouseMove(GLFWwindow *window, double x, double y);
void onMouseClick(GLFWwindow *window, int button, int action, int modifiers);
vec2 *getClickedPoint(const vec2& cursorPosition, std::vector<vec2>& controlPoints);

int main(int argc, char **argv) {
	glfwInit();
	glfwSetTime(0);

	GLFWwindow *window = createWindow();

	if (window == nullptr) {
		std::cerr << "Failed to create GLFW window!" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

#if defined(NANOGUI_GLAD)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Could not initialize GLAD!" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Pull and ignore unhandled errors like GL_INVALID_ENUM.
	glGetError();
#endif

	// Create a NanoGUI screen and pass the GLFW pointer to initialize.
	screen = new nanogui::Screen();
	screen->initialize(window, true);

	int frameBufferWidth, frameBufferHeight;
	glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.f, frameBufferWidth, frameBufferHeight, 0.f, 0.f, 1.f);
	glPointSize(4.0f);
	

	glfwSwapInterval(0);
	glfwSwapBuffers(window);

	nanogui::Window *controlWindow = new nanogui::Window(screen, "Controls");
	controlWindow->setPosition(nanogui::Vector2i(15, 15));
	controlWindow->setLayout(new nanogui::GroupLayout());

	nanogui::Widget *panel = new nanogui::Widget(controlWindow);
	panel->setLayout(new nanogui::BoxLayout(
		nanogui::Orientation::Horizontal,
		nanogui::Alignment::Middle,
		0,
		20
	));

	nanogui::Label *tensionLabel = new nanogui::Label(panel, "Tension");

	nanogui::Slider *tensionSlider = new nanogui::Slider(panel);
	tensionSlider->setRange({ -5.0f, 5.0f });
	tensionSlider->setValue(0.0f);
	tensionSlider->setFixedWidth(100);

	nanogui::Label *tensionValueLabel =
		new nanogui::Label(panel, "0.0");
	tensionValueLabel->setFixedWidth(100);

	tensionSlider->setCallback([tensionValueLabel](float value) {
		tensionValueLabel->setCaption(std::to_string(value));
		tension = value;
	});


	nanogui::Widget *checkboxPanel = new nanogui::Widget(controlWindow);
	checkboxPanel->setLayout(new nanogui::BoxLayout(
		nanogui::Orientation::Horizontal,
		nanogui::Alignment::Middle,
		0,
		20
	));

	nanogui::CheckBox *controlPolygonCheckBox =
		new nanogui::CheckBox(checkboxPanel, "Show control polygon");
	controlPolygonCheckBox->setChecked(true);
	controlPolygonCheckBox->setCallback([](bool value) {
		isDrawControlPolygon = value;
	});

	screen->setVisible(true);
	screen->performLayout();

	setupInputCallbacks(window);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(0.329f, 0.431f, 0.478f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		if (controlPoints.size() >= MINIMUM_NUMBER_OF_CONTROL_POINTS) {
			const mat4 coefficientMatrix = calculateCoefficientMatrix(tension, bias, continuity);

			drawCurve(coefficientMatrix, controlPoints);
		}

		if (isDrawControlPolygon) {
			drawControlPolygon(controlPoints);
		}

		if (isDrawControlPoints) {
			drawControlPoints(controlPoints);
		}

		// Draw NanoGUI.
		screen->drawContents();
		screen->drawWidgets();

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}

GLFWwindow *createWindow() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, CONTEXT_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, CONTEXT_VERSION_MINOR);

	glfwWindowHint(GLFW_SAMPLES, 0);
	glfwWindowHint(GLFW_RED_BITS, 8);
	glfwWindowHint(GLFW_GREEN_BITS, 8);
	glfwWindowHint(GLFW_BLUE_BITS, 8);
	glfwWindowHint(GLFW_ALPHA_BITS, 8);
	glfwWindowHint(GLFW_STENCIL_BITS, 8);
	glfwWindowHint(GLFW_DEPTH_BITS, 24);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	return glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, APPLICATION_TITLE, nullptr, nullptr);
}

void setupInputCallbacks(GLFWwindow * const window) {
	glfwSetCursorPosCallback(window, onMouseMove);

	glfwSetMouseButtonCallback(window, onMouseClick);

	glfwSetKeyCallback(window,
		[](GLFWwindow *, int key, int scancode, int action, int mods) {
			screen->keyCallbackEvent(key, scancode, action, mods);
		}
	);

	glfwSetCharCallback(window,
		[](GLFWwindow *, unsigned int codepoint) {
			screen->charCallbackEvent(codepoint);
		}
	);

	glfwSetDropCallback(window,
		[](GLFWwindow *, int count, const char **filenames) {
			screen->dropCallbackEvent(count, filenames);
		}
	);

	glfwSetScrollCallback(window,
		[](GLFWwindow *, double x, double y) {
			screen->scrollCallbackEvent(x, y);
		}
	);

	glfwSetFramebufferSizeCallback(window,
		[](GLFWwindow *, int width, int height) {
			screen->resizeCallbackEvent(width, height);
		}
	);
}

void onMouseMove(GLFWwindow *window, double x, double y) {
	const bool isHandledByGui = screen->cursorPosCallbackEvent(x, y);

	if (isHandledByGui) {
		draggedControlPoint = nullptr;
	} else if (draggedControlPoint != nullptr) {
		draggedControlPoint->x = (float)x;
		draggedControlPoint->y = (float)y;
	}
}

void onMouseClick(GLFWwindow *window, int button, int action, int modifiers) {
	const bool isHandledByGui = screen->mouseButtonCallbackEvent(button, action, modifiers);

	if (!isHandledByGui && button == GLFW_MOUSE_BUTTON_LEFT) {

		if (action == GLFW_PRESS) {
			double xpos, ypos;

			glfwGetCursorPos(window, &xpos, &ypos);

			const vec2 cursorPosition = { (float)xpos, (float)ypos };

			vec2 *pointUnderCursor = getClickedPoint(cursorPosition, controlPoints);

			if (pointUnderCursor == nullptr) {
				controlPoints.push_back(cursorPosition);
			}
			else {
				draggedControlPoint = pointUnderCursor;
			}
		}
		else if (action == GLFW_RELEASE) {
			draggedControlPoint = nullptr;
		}
	}
}

mat4 calculateCoefficientMatrix(const float tension, const float bias, const float continuity) {
	const float s = 0.5f * (1.0f - tension);
	const float q1 = s * (1.0f + bias) * (1.0f - continuity);
	const float q2 = s * (1.0f - bias) * (1.0f + continuity);
	const float q3 = s * (1.0f + bias) * (1.0f + continuity);
	const float q4 = s * (1.0f - bias) * (1.0f - continuity);

	return {
		{ -q1, 2.0f * q1, -q1, 0 },
		{ q1 - q2 - q3 + 2.0f, q3 - (2.0f * q1) + (2.0f * q2) - 3.0f, q1 - q2, 1.0f },
		{ q2 + q3 - q4 - 2.0f, q4 - q3 - (2.0f * q2) + 3.0f, q2, 0 },
		{ q4, -q4, 0, 0}
	};
}

void drawCurve(const mat4& coefficientMatrix, const std::vector<vec2>& controlPoints) {
	const size_t segmentCount = controlPoints.size() - 3;

	glLineWidth(2.5f);
	glColor3ub(255, 171, 64);
	glBegin(GL_LINE_STRIP);
	for (size_t segmentIndex = 0; segmentIndex < segmentCount; ++segmentIndex) {
		drawSegment(segmentIndex, coefficientMatrix, controlPoints);
	}
	glEnd();
}

void drawSegment(const size_t segmentIndex, const mat4& coefficientMatrix, const std::vector<vec2>& controlPoints) {
	const mat24 geometry = {
		controlPoints[segmentIndex + 0],
		controlPoints[segmentIndex + 1],
		controlPoints[segmentIndex + 2],
		controlPoints[segmentIndex + 3]
	};

	const mat24 gm = geometry * coefficientMatrix;

	for (float t = 0.0f; t <= 1.0f + PARAMETER_DELTA; t += PARAMETER_DELTA) {
		const vec4 parameterVector = { t * t * t, t * t, t, 1.0f };

		const vec2 curvePoint = gm * parameterVector;

		glVertex2f(curvePoint.x, curvePoint.y);
	}
}

void drawControlPolygon(const std::vector<vec2>& controlPoints) {
	glLineWidth(1.5f);
	glColor3ub(255, 255, 255);
	glBegin(GL_LINE_STRIP);
	for (const auto& point : controlPoints) {
		glVertex2f(point.x, point.y);
	}
	glEnd();
}

void drawControlPoints(const std::vector<vec2>& controlPoints) {
	glColor3ub(255, 255, 255);
	glBegin(GL_POINTS);
	for (const auto& point : controlPoints) {
		glVertex2f(point.x, point.y);
	}
	glEnd();
}

vec2 *getClickedPoint(const vec2& cursorPosition, std::vector<vec2>& controlPoints)
{
	const auto clickedIterator = std::find_if(controlPoints.begin(), controlPoints.end(), [&cursorPosition](const vec2& point) {
		return dist2(cursorPosition, point) <= CLICK_THRESHOLD;
	});

	if (clickedIterator == controlPoints.end()) {
		return nullptr;
	} else {
		return &(*clickedIterator);
	}
}
