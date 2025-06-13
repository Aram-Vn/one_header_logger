#include "../logger.hpp"

#include <string>

int main()
{
    std::string str = "test";
    log_info("info with args: %s at %d baud\n", str.c_str(), 15);
    log_error("err test\n");
    log_warn("warn test  %c\n", 'f');
    log_debug("some debug\n");

    for (int i = 0; i < 5; ++i)
    {
        log_info("log_info %i\n", i);
        log_once_info("log_once_info\n");
        log_once_debug("log_once_debug\n");
        log_once_warn("log_once_warn\n");
        log_once_error("log_once_error\n");
    }
}