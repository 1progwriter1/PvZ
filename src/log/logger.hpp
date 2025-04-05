#ifndef PLANTSVSZOMBIES_SRC_LOG_LOGGER_HPP_
#define PLANTSVSZOMBIES_SRC_LOG_LOGGER_HPP_

#include <filesystem>
#include <fstream>

namespace logger {

const std::filesystem::path LOG_FILE = "../log.txt";

class Logger {
 public:
    static Logger &getInstance();
    std::fstream &getStream();
 private:
    Logger();
 private:
    std::fstream stream_;
};

std::fstream &getLogStream();

} // logger

#endif //PLANTSVSZOMBIES_SRC_LOG_LOGGER_HPP_
