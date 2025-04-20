#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

class Logger {
private:
    std::deque<std::string> logs;
    const size_t maxLogs = 1000;

    std::string formatMessage(const std::string& severity, const std::string& module, const std::string& message) {
        return "[" + severity + "] (" + module + "): " + message;
    }

    void addLog(const std::string& formattedMessage) {
        if (logs.size() >= maxLogs) {
            logs.pop_front();
        }
        logs.push_back(formattedMessage);
    }

public:
    void log(const std::string& severity, const std::string& module, const std::string& message) {
        std::string formatted = formatMessage(severity, module, message);
        addLog(formatted);
    }

    void logInfo(const std::string& module, const std::string& message) {
        log("INFO", module, message);
    }

    void logWarning(const std::string& module, const std::string& message) {
        log("WARN", module, message);
    }

    void logError(const std::string& module, const std::string& message) {
        log("ERROR", module, message);
    }

    friend class Auditor;
};

class Auditor {
private:
    std::string password;

    bool authenticate(const std::string& input) const {
        return input == password;
    }

public:
    Auditor(const std::string& pw) : password(pw) {}

    std::vector<std::string> retrieveLogs(const Logger& logger, const std::string& inputPassword) const {
        if (!authenticate(inputPassword)) return {};
        return std::vector<std::string>(logger.logs.begin(), logger.logs.end());
    }
};

int main() {
    Logger logger;

    logger.logInfo("Network Module", "Connected to server.");
    logger.logWarning("Database Module", "Query took too long.");
    logger.logError("UI Module", "Null pointer exception.");

    for (int i = 0; i < 1002; ++i) {
        logger.logInfo("Overflow Module", "Filling up logs...");
    }

    Auditor auditor("securepass");

    std::vector<std::string> logs = auditor.retrieveLogs(logger, "securepass");
    for (const auto& log : logs) {
        std::cout << log << std::endl;
    }

    return 0;
}

