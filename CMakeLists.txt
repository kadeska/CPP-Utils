cmake_minimum_required(VERSION 3.15)

project(Utils VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Always disable Wayland unless you want to build with it
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Disable Wayland" FORCE)
set(GLFW_BUILD_X11 ON CACHE BOOL "Enable X11" FORCE)

# Detect if we're running in GitHub Actions (CI)
if(DEFINED ENV{CI})
    set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Disable Wayland" FORCE)
    set(GLFW_BUILD_X11 ON CACHE BOOL "Enable X11" FORCE)
endif()

# --------------------------------------------------
# Dependencies via FetchContent (GLFW and GLM)
include(FetchContent)

# GLFW
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG latest
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Disable GLFW docs" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Disable GLFW tests" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Disable GLFW examples" FORCE)
FetchContent_MakeAvailable(glfw)

# GLM
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 0.9.9.8
)
FetchContent_MakeAvailable(glm)

# --------------------------------------------------
# Add glad
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/glad.c)

# Define the executable and source files
add_executable(Utils 
    main.cpp 
    customLogging.cpp 
    graphics/window/window.cpp 
    graphics/rendering/opengl/glrenderer.cpp
    graphics/rendering/opengl/program.cpp
    graphics/rendering/opengl/camera.cpp
    world/world.cpp
    world/worldGenerator_A.cpp
    ${GLAD_SRC}
)

# Include directories for your own headers
target_include_directories(Utils PRIVATE 
    include_headers
    include_headers/3rdparty
    ${CMAKE_SOURCE_DIR}
)

# Find OpenGL package
find_package(OpenGL REQUIRED)

# Link against required libraries
target_link_libraries(Utils PRIVATE 
    OpenGL::GL 
    glfw 
    glm 
    dl
)

# Copy shader files to build directory
add_custom_command(TARGET Utils POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/graphics/shaders
    ${CMAKE_BINARY_DIR}/shaders
)
