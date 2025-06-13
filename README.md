# One-Header Logger for C++

A simple, header-only logging utility for C++ with:

- ANSI-colored log levels (`DEBUG`, `INFO`, `WARN`, `ERROR`)
- Optional thread safety with `std::mutex`
- Compile-time log filtering (based on `LOG_LEVEL_THRESHOLD`)
- GNU-style variadic macros with fallback for standard C++
- Zero runtime cost for disabled log levels

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
