#pragma once

#include <iostream>
#include <string>

namespace CustomLogging
{
    enum class LogLevel
    {
        INFO,
        WARNING,
        ERROR,
        DEBUG
    };

    void log(const std::string& message, LogLevel level = LogLevel::INFO)
    {
        switch (level)
        {
            case LogLevel::INFO:
                std::cout << "[INFO] " << message << std::endl;
                break;
            case LogLevel::WARNING:
                std::cout << "[WARNING] " << message << std::endl;
                break;
            case LogLevel::ERROR:
                std::cerr << "[ERROR] " << message << std::endl;
                break;
            case LogLevel::DEBUG:
                std::cout << "[DEBUG] " << message << std::endl;
                break;
        }
    }
}