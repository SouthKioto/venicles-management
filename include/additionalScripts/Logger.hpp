#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <string>

enum LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };

class Logger {
private:
  std::ofstream logFile;
  std::string levelToString(LogLevel level);

public:
  Logger(const std::string &filename);
  ~Logger();

  void log(LogLevel level, const std::string &message);
};

#endif // LOGGER_HPP
