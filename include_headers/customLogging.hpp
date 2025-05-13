#ifndef CUSTOM_LOGGING_HPP
#define CUSTOM_LOGGING_HPP

#include <iostream>
#include <string>
#include <sstream>

namespace CustomLogging
{

    /**
     * @brief The LogLevel enum represents the different log levels.
     * INFO: General information messages.
     * WARNING: Warning messages indicating potential issues.
     * ERROR: Error messages indicating failures.
     * DEBUG: Debugging messages for development purposes.
     * @note The log levels are ordered from least to most severe.
     * INFO < WARNING < ERROR < DEBUG
     * @note The log levels are used to set how much information is printed to the console.
     */
    enum class LogLevel
    {
        INFO,
        WARNING,
        ERROR,
        DEBUG
    };

    /**
     * @brief Logs a message to the console with the specified log level.
     * @param message The message to log.
     * @param level The log level (INFO, WARNING, ERROR, DEBUG).
     * @param overide If true, overrides the current log level. If this overide flag is set to true then the message will be logged regardless of the global log level.
     */
    void log(const std::string &message, LogLevel level = LogLevel::INFO, bool overide = false);

    /**
     * @brief The global program log level variable.
     * @note This can be set to (0)INFO, (1)WARNING, (2)ERROR, or (3)DEBUG.
     * @note The default value is (0)INFO if no value is given at the command line when running this program.
     */
    extern LogLevel progLogLevel;

    /**
     * @brief Checks if a string is a valid integer value, and converts it to an integer.
     * @param string The string to check.
     * @param result The integer value if the string is valid.
     * @return True if the string is a valid integer, false otherwise.
     */
    bool isValidInt(const std::string &string, int &result);

    /**
     * @brief Converts a LogLevel enum to a string representation.
     * @param level The LogLevel to convert to a string.
     * @return The corresponding string value.
     */
    std::string logLevelToString(LogLevel level);

    /**
     * @brief Parses command line arguments to set the log level.
     * @param argc The number of command line arguments.
     * @param argv The command line arguments.
     * @return The parsed log level.
     */
    LogLevel parseLogLevel(int argc, char *argv[]);

    /**
     * @brief Prints the command line arguments.
     * @param argc The number of command line arguments.
     * @param argv The command line arguments.
     */
    void printCommandLineArguments(int argc, char *argv[]);
}

#endif // CUSTOM_LOGGING_HPP