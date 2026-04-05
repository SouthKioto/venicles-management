#include "../include/database/Database.hpp"

Database::Database(std::string filename) : filename(filename) {
  this->filename = filename;
}
