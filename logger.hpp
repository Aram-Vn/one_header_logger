#pragma once

#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO  1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_ERROR 3

// Default to INFO if not defined by compiler flags
#ifndef LOG_LEVEL_THRESHOLD
#define LOG_LEVEL_THRESHOLD 0
#endif

#define COLOR(x) x
#define RED      COLOR("\033[1;31m")
#define YELLOW   COLOR("\033[1;33m")
#define GREEN    COLOR("\033[1;32m")
#define BLUE     COLOR("\033[1;34m")
#define RESET    COLOR("\033[0m")

#undef log

// Optional thread safety
#ifdef ENABLE_LOG_MUTEX
#include <mutex>
inline std::mutex log_mutex;
#define LOCK_LOG() std::lock_guard<std::mutex> lock(log_mutex)
#else
#define LOCK_LOG() (void)0
#endif

#if defined(__GNUC__) && !defined(__clang__)
// GNU-style macro with ##__VA_ARGS__
#define log(level, fmt, ...)                                                                                           \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((level) >= LOG_LEVEL_THRESHOLD)                                                                            \
        {                                                                                                              \
            LOCK_LOG();                                                                                                \
            const char* lvl_str = (level == LOG_LEVEL_ERROR)  ? "[" RED "ERROR" RESET "]"                              \
                                  : (level == LOG_LEVEL_WARN) ? "[" YELLOW "WARN" RESET "]"                            \
                                  : (level == LOG_LEVEL_INFO) ? "[" GREEN "INFO" RESET "]"                             \
                                                              : "[" BLUE "DEBUG" RESET "]";                            \
            if (level == LOG_LEVEL_INFO || level == LOG_LEVEL_DEBUG)                                                   \
            {                                                                                                          \
                fprintf(stderr, "%s ", lvl_str);                                                                       \
            }                                                                                                          \
            else                                                                                                       \
            {                                                                                                          \
                fprintf(stderr, "%s %s:%d %s(): ", lvl_str, __FILE__, __LINE__, __func__);                             \
            }                                                                                                          \
            fprintf(stderr, fmt, ##__VA_ARGS__);                                                                       \
        }                                                                                                              \
    } while (0)
#else
// C++ standard-compliant version
#define log(level, ...)                                                                                                \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((level) >= LOG_LEVEL_THRESHOLD)                                                                            \
        {                                                                                                              \
            LOCK_LOG();                                                                                                \
            const char* lvl_str = (level == LOG_LEVEL_ERROR)  ? "[" RED "ERROR" RESET "]"                              \
                                  : (level == LOG_LEVEL_WARN) ? "[" YELLOW "WARN" RESET "]"                            \
                                  : (level == LOG_LEVEL_INFO) ? "[" GREEN "INFO" RESET "]"                             \
                                                              : "[" BLUE "DEBUG" RESET "]";                            \
            if (level == LOG_LEVEL_INFO || level == LOG_LEVEL_DEBUG)                                                   \
            {                                                                                                          \
                fprintf(stderr, "%s ", lvl_str);                                                                       \
            }                                                                                                          \
            else                                                                                                       \
            {                                                                                                          \
                fprintf(stderr, "%s %s:%d %s(): ", lvl_str, __FILE__, __LINE__, __func__);                             \
            }                                                                                                          \
            fprintf(stderr, __VA_ARGS__);                                                                              \
        }                                                                                                              \
    } while (0)
#endif

// Logging functions
#define log_debug(...) log(LOG_LEVEL_DEBUG, __VA_ARGS__)
#define log_info(...)  log(LOG_LEVEL_INFO, __VA_ARGS__)
#define log_warn(...)  log(LOG_LEVEL_WARN, __VA_ARGS__)
#define log_error(...) log(LOG_LEVEL_ERROR, __VA_ARGS__)
