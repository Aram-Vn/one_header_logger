#define ENABLE_LOG_MUTEX
#define LOG_LEVEL_THRESHOLD LOG_LEVEL_WARN

#include "logger.hpp"

#include <string>


int main()
{
    std::string str = "test";
    log_info("info with args: %s at %d baud\n", str.c_str(), 15);
    log_error("err test\n");
    log_warn("warn test  %c\n", 'f');
    log_debug("some debug\n");
}