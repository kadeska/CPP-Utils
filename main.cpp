#include "include_headers/CustomLogging.hpp"

int main(int argc, char* argv[])
{
    // Example usage of the CustomLogging library
    CustomLogging::log("This is an info message.");
    CustomLogging::log("This is a warning message.", CustomLogging::LogLevel::WARNING);
    CustomLogging::log("This is an error message.", CustomLogging::LogLevel::ERROR);
    CustomLogging::log("This is a debug message.", CustomLogging::LogLevel::DEBUG);

    return 0;
}