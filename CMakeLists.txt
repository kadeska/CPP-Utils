cmake_minimum_required(VERSION 3.15)

project(Utils VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenGL package
find_package(OpenGL REQUIRED)

# Add glad.c as a source file
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/glad.c)

# Add the executable
add_executable(Utils 
    main.cpp 
    customLogging.cpp 
    graphics/window/window.cpp 
    ${GLAD_SRC}
)

# Include directories
target_include_directories(Utils PRIVATE 
    include_headers
    include_headers/3rdparty
    ${CMAKE_SOURCE_DIR}
)

# Link libraries
target_link_libraries(Utils PRIVATE 
    OpenGL::GL 
    glfw
    dl
)