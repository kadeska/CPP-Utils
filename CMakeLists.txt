cmake_minimum_required(VERSION 3.15)

project(Utils VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dependencies
find_package(OpenGL REQUIRED)

# Detect if we're running in GitHub Actions (CI)
if(DEFINED ENV{CI})
    # Disable Wayland, enable X11 on CI runners
    set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Disable Wayland" FORCE)
    set(GLFW_BUILD_X11 ON CACHE BOOL "Enable X11" FORCE)
endif()

# ----------------------------
# Fetch GLFW using FetchContent
include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG latest
)

# Disable tests/docs/examples
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Disable GLFW docs" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Disable GLFW tests" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Disable GLFW examples" FORCE)

FetchContent_MakeAvailable(glfw)
# ----------------------------

# Use FetchContent to get GLFW
include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG latest
)

# Disable unnecessary parts of GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW Docs" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW Tests" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW Examples" FORCE)

FetchContent_MakeAvailable(glfw)

# Add glad
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/glad.c)

# Define the executable
add_executable(Utils 
    main.cpp 
    customLogging.cpp 
    graphics/window/window.cpp 
    graphics/rendering/opengl/glrenderer.cpp
    graphics/rendering/opengl/program.cpp
    ${GLAD_SRC}
)

# Include directories for your own project (NOT for GLFW!)
target_include_directories(Utils PRIVATE 
    include_headers
    include_headers/3rdparty
    ${CMAKE_SOURCE_DIR}
)

# Link against OpenGL and GLFW (which provides its own include dirs)
target_link_libraries(Utils PRIVATE 
    OpenGL::GL 
    glfw 
    dl
)
