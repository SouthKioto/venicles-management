#include "../include/database/DatabaseJson.hpp"

Database::Database(std::string filename) : filename(filename) {
  this->logger.log(LogLevel::Info, "Database initialized with file: " + filename);
}

Database::~Database() {
}
