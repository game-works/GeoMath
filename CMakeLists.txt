# Minimum CMake version needed.
cmake_minimum_required(VERSION 3.4)

# Project name (no spaces)
project(MathProject)

# Your variables
set(LIB_IMGUI "includes/imgui")
set(LIB_IMGUI_SFML "includes/imgui-sfml")
set(OUTPUT_NAME "app")

# Find OpenGL
# See https://cmake.org/cmake/help/v3.0/module/FindOpenGL.html for more info
find_package(OpenGL REQUIRED)

# Additional include directories
include_directories(${OPENGL_INCLUDE_DIR} ${LIB_IMGUI} ${LIB_IMGUI_SFML})

# Executable name is "app"
add_executable(${OUTPUT_NAME}
    # List of source files
    src/main.cpp
    src/application.cpp
    src/menu.cpp
    src/popup.cpp
    ${LIB_IMGUI}/imgui.cpp
    ${LIB_IMGUI}/imgui_draw.cpp
    ${LIB_IMGUI}/imgui_widgets.cpp
    ${LIB_IMGUI_SFML}/imgui-SFML.cpp
)

# What must be linked to the app
target_link_libraries(${OUTPUT_NAME} ${OPENGL_LIBRARIES} sfml-graphics sfml-window sfml-system)
install(TARGETS ${OUTPUT_NAME} DESTINATION .)
