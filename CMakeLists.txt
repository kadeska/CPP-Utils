cmake_minimum_required(VERSION 3.15)

project(Utils VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenGL package
find_package(OpenGL REQUIRED)

# Disable Wayland in CI (like GitHub Actions), enable otherwise
if(DEFINED ENV{CI})
    set(GLFW_USE_WAYLAND OFF CACHE BOOL "Disable Wayland in CI" FORCE)
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

# Add glad.c as a source file
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/glad.c)

# Add the executable
add_executable(Utils 
    main.cpp 
    customLogging.cpp 
    graphics/window/window.cpp 
    graphics/rendering/opengl/glrenderer.cpp
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
