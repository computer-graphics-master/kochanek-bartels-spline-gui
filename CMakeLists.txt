cmake_minimum_required (VERSION 3.9.0)
project (kochanek-bartels-spline-gui)

# Behúzzuk a header fájlokat.
include_directories(include)
include_directories(ext/nanogui/include)

# Megmondjuk, hogy hol keresse a CMake a forrásfájlokat.
file(GLOB SOURCES "src/*.cpp")

# A NanoGUI-ra csak mint könyvtárra van szükségünk, így minden pluszt kikapcsolunk.
set(NANOGUI_BUILD_EXAMPLE OFF CACHE BOOL " " FORCE)
set(NANOGUI_BUILD_PYTHON  OFF CACHE BOOL " " FORCE)
set(NANOGUI_INSTALL       OFF CACHE BOOL " " FORCE)
# Statikusan szeretnénk linkelni a NanoGUI-t, ezért a következő kapcsolót is kiütjük.
set(NANOGUI_BUILD_SHARED  OFF CACHE BOOL " " FORCE)

# lsd.: docs/fuggosegek.md
add_definitions(-DNANOVG_GL_NO_UNIFORMBUFFER)

# Hozzáadjuk a NanoGUI-t tartalmazó könyvtárat, amit így szintén fel fog dolgozni a CMake.
add_subdirectory(ext/nanogui)

# Konfiguráció a NanoGUI-hoz.
set_property(TARGET glfw glfw_objects nanogui PROPERTY FOLDER "dependencies")
add_definitions(${NANOGUI_EXTRA_DEFS})
include_directories(${NANOGUI_EXTRA_INCS})

# Fordítjuk az src mappában található forrásokat.
add_executable(kochanek-bartels-spline-gui ${SOURCES})

set_property(TARGET kochanek-bartels-spline-gui PROPERTY CXX_STANDARD 17)

# Linkeljük az előzőleg létrejött tárgykódú állományokat a NanoGUI-val, létrehozva
# az kochanek-bartels-spline-gui futtatható állománytt.
target_link_libraries(kochanek-bartels-spline-gui nanogui ${NANOGUI_EXTRA_LIBS})
