/*
	Based on NanoGUI src/example3.cpp.

	NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
	The widget drawing code is based on the NanoVG demo application
	by Mikko Mononen.
*/

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


GLFWwindow *createWindow();
void setupInputCallbacks(GLFWwindow * const window);


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

	glfwSwapInterval(0);
	glfwSwapBuffers(window);

	screen->setVisible(true);
	screen->performLayout();

	setupInputCallbacks(window);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(0.33f, 0.33f, 0.33f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2d(100, 100);
		glVertex2d(200, 100);
		glVertex2d(150, 200);
		glEnd();

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
	glfwSetCursorPosCallback(window,
		[](GLFWwindow *, double x, double y) {
			screen->cursorPosCallbackEvent(x, y);
		}
	);

	glfwSetMouseButtonCallback(window,
		[](GLFWwindow *, int button, int action, int modifiers) {
			screen->mouseButtonCallbackEvent(button, action, modifiers);
		}
	);

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
