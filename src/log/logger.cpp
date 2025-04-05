#include "logger.hpp"

#include <cassert>
#include <iostream>

namespace logger {

Logger::Logger()
    :   stream_(LOG_FILE) {
    assert(stream_.is_open());
}

Logger &Logger::getInstance() {
    static Logger logger;
    return logger;
}

std::fstream &Logger::getStream() {
    return stream_;
}

std::fstream &getLogStream() {
    return Logger::getInstance().getStream();
}

} // log