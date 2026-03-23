#include "../../include/additionalScripts/Logger.hpp"

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

Logger::Logger(const std::string &filename) {
  logFile.open(filename, std::ios::app);
  if (!logFile.is_open()) {
    std::cerr << "Error opening log file" << std::endl;
  }
}

Logger::~Logger() {
  if (logFile.is_open()) {
    logFile.close();
  }
}

std::string Logger::levelToString(LogLevel level) {
  switch (level) {
  case WARNING:
    return "WARNING";

  case DEBUG:
    return "DEBUG";

  case INFO:
    return "INFO";

  case ERROR:
    return "ERROR";

  case CRITICAL:
    return "CRITICAL";
  }
};

void Logger::log(LogLevel level, const std::string &message) {
  time_t now = time(0);
  tm *timeInfo = localtime(&now);

  char timestamp[20];

  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeInfo);

  std::ostringstream logEntry;

  logEntry << "[" << timestamp << "]" << levelToString(level) << ": " << message
           << std::endl;

  std::cout << logEntry.str();

  if (logFile.is_open()) {
    logFile << logEntry.str();
    logFile.flush();
  }
}
