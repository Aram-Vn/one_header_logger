# One-Header Logger for C++

A simple, header-only logging utility for C++ with:

- ANSI-colored log levels (`DEBUG`, `INFO`, `WARN`, `ERROR`)
- Optional thread safety with `std::mutex`
- Compile-time log filtering (based on `LOG_LEVEL_THRESHOLD`)
- log_once_* macros for one-time log messages
- GNU-style variadic macros with fallback for standard C++
- Zero runtime cost for disabled log levels

---

## Table of Contents

- [Log Levels](#log-levels)
- [Configuration](#configuration)
  - [Set Log Level Threshold](#set-log-level-threshold)
  - [Enable Thread-Safe Logging](#enable-thread-safe-logging)
- [Example Usage](#example-usage)
- [One-Time Logging Example](#one-time-logging)

---

## Log Levels

| Level | Value | Description       | Color  |
| ----- | ----- | ----------------- | ------ |
| DEBUG | `0`   | Developer details | Blue   |
| INFO  | `1`   | General info      | Green  |
| WARN  | `2`   | Warnings          | Yellow |
| ERROR | `3`   | Errors only       | Red    |

---

## Configuration

### Set Log Level Threshold

Suppress lower-priority logs by defining `LOG_LEVEL_THRESHOLD` **before including** `logger.hpp`.

**Example (in code):**

```cpp
#define LOG_LEVEL_THRESHOLD <LEVEL>
#include "logger.hpp"

```cpp
#define LOG_LEVEL_THRESHOLD LOG_LEVEL_DEBUG
#define LOG_LEVEL_THRESHOLD LOG_LEVEL_INFO
#define LOG_LEVEL_THRESHOLD LOG_LEVEL_WARN
#define LOG_LEVEL_THRESHOLD LOG_LEVEL_ERROR
```

**Or via compiler flags:**

```sh
-DLOG_LEVEL_THRESHOLD=LOG_LEVEL_DEBUG
-DLOG_LEVEL_THRESHOLD=LOG_LEVEL_INFO
-DLOG_LEVEL_THRESHOLD=LOG_LEVEL_WARN
-DLOG_LEVEL_THRESHOLD=LOG_LEVEL_ERROR
```

**Or in CMake:**

```cmake
add_compile_definitions(LOG_LEVEL_DEBUG)
add_compile_definitions(LOG_LEVEL_INFO)
add_compile_definitions(LOG_LEVEL_WARN)
add_compile_definitions(LOG_LEVEL_ERROR)
```

---

## Enable Thread-Safe Logging

**Example (in code):**

```cpp
#define ENABLE_LOG_MUTEX
#include "logger.hpp"

```

**Or via compiler flags:**

```sh
-DENABLE_LOG_MUTEX
```

**Or in CMake:**

```cmake
add_compile_definitions(ENABLE_LOG_MUTEX)
```

## Example Usage

```cpp
#include "logger.hpp"

int main() {
    log_debug("Debug message: x = %d\n", 42);
    log_info("App started at %s\n", "10:00AM");
    log_warn("Low memory warning\n");
    log_error("File not found: %s\n", "config.json");
}
```

output will be

![Image](https://github.com/user-attachments/assets/19e5f7ff-549b-40b9-a18b-66ccaf7c849d)

---

## One-Time Logging

Use `log_once_*` macros to emit a log message **only once** per call site, even inside loops. This is useful to avoid flooding the logs with repeated warnings or debug messages.

### Available Macros

- `log_once_debug(...)`
- `log_once_info(...)`
- `log_once_warn(...)`
- `log_once_error(...)`

### Example

```cpp
for (int i = 0; i < 10; ++i) {
    log_once_info("log_once_info\n");
    log_once_debug("log_once_debug\n");
    log_once_warn("log_once_warn\n");
    log_once_error("log_once_error\n");
}
```

```sh
[INFO] log_once_info
[DEBUG] log_once_debug
[WARN] main.cpp:XX main(): log_once_warn
[ERROR] main.cpp:XX main(): log_once_error
```

Each message prints only once, even though the loop runs multiple times.
