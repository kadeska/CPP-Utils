#include "include_headers/customLogging.hpp"
#include "include_headers/window.hpp"
#include "include_headers/glrenderer.hpp"

#include "math.hpp"

int main(int argc, char *argv[])
{
    CustomLogging::printCommandLineArguments(argc, argv);
    CustomLogging::parseLogLevel(argc, argv);
    CustomLogging::parseArguments(argc, argv);
    // CustomLogging::progLogLevel = CustomLogging::LogLevel::DEBUG;
    // Example usage of the CustomLogging library
    CustomLogging::log("This is an info message.");
    CustomLogging::log("This is a warning message.", CustomLogging::LogLevel::WARNING);
    CustomLogging::log("This is an error message.", CustomLogging::LogLevel::ERROR);
    CustomLogging::log("This is a debug message.", CustomLogging::LogLevel::DEBUG);

    // testing the window

    // check if window iniialization is successful
    // this must be done before calling createWindow.
    if (initialize() == -1)
    {
        CustomLogging::log("Failed to initialize GLFW", CustomLogging::LogLevel::ERROR, true);
        return -1;
    }

    renderWindow(createWindow(800, 600, "OpenGL Window"));
    // createWindow(800, 600, "OpenGL Window");
    // draw();

    // log(std::to_string(getRandomInt(1, 10)), CustomLogging::LogLevel::DEBUG);
    // log(std::to_string(getRandomInt()), CustomLogging::LogLevel::DEBUG);
    // srand(99);
    // log(std::to_string(rand()), CustomLogging::LogLevel::DEBUG);

    return 0;
}