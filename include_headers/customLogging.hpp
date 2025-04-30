#ifndef CUSTOM_LOGGING_HPP
#define CUSTOM_LOGGING_HPP

#include <iostream>
#include <string>
#include <sstream>

namespace CustomLogging
{
    enum class LogLevel
    {
        INFO,
        WARNING,
        ERROR,
        DEBUG
    };

    extern LogLevel progLogLevel; // Declare the variable

    bool isValidInt(const std::string &string, int &result); // Declare the function
    std::string logLevelToString(LogLevel level);           // Declare the function
    void log(const std::string &message, LogLevel level = LogLevel::INFO, bool overide = false); // Declare the function
    LogLevel parseLogLevel(int argc, char *argv[]);         // Declare the function
    void printCommandLineArguments(int argc, char *argv[]); // Declare the function
}

#endif // CUSTOM_LOGGING_HPP