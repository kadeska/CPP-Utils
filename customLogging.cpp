#include "customLogging.hpp"

namespace CustomLogging
{
    LogLevel progLogLevel = LogLevel::INFO; // Define the variable

    bool isValidInt(const std::string &string, int &result)
    {
        try
        {
            size_t pos;
            result = std::stoi(string, &pos);
            return pos == string.length();
        }
        catch (const std::exception &)
        {
            return false;
        }
    }

    std::string logLevelToString(LogLevel level)
    {
        switch (level)
        {
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::DEBUG:
            return "DEBUG";
        default:
            return "UNKNOWN";
        }
    }

    void log(const std::string &message, LogLevel level, bool overide)
    {
        if (overide || static_cast<int>(level) <= static_cast<int>(progLogLevel))
        {
            std::ostream &out = (level == LogLevel::ERROR) ? std::cerr : std::cout;
            out << "[" << logLevelToString(level) << "] [LOG]: " << message << std::endl;
        }
    }

    LogLevel parseLogLevel(int argc, char *argv[])
    {
        if (argc > 1)
        {
            int logLevel = 0;
            std::string arg1 = argv[1];
            if (isValidInt(arg1, logLevel) && logLevel >= 0 && logLevel <= 3)
            {
                progLogLevel = static_cast<LogLevel>(logLevel);
            }
        }
        return progLogLevel;
    }

    void printCommandLineArguments(int argc, char *argv[])
    {
        std::ostringstream out;
        out << "main(argc: " << argc << ", argv: [";
        for (int i = 0; i < argc; ++i)
        {
            out << "\"" << argv[i] << "\"";
            if (i < argc - 1)
                out << ", ";
        }
        out << "])";
        log(out.str(), LogLevel::DEBUG);
    }
}