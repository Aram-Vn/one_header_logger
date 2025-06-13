# one_header_logger

log levels setup

```cpp
#define LOG_LEVEL_THRESHOLD LOG_LEVEL_DEBUG
#define LOG_LEVEL_THRESHOLD LOG_LEVEL_INFO
#define LOG_LEVEL_THRESHOLD LOG_LEVEL_WARN
#define LOG_LEVEL_THRESHOLD LOG_LEVEL_ERROR
```

or give flag

```sh
-DLOG_LEVEL_THRESHOLD=LOG_LEVEL_DEBUG
-DLOG_LEVEL_THRESHOLD=LOG_LEVEL_INFO
-DLOG_LEVEL_THRESHOLD=LOG_LEVEL_WARN
-DLOG_LEVEL_THRESHOLD=LOG_LEVEL_ERROR

```

```cmake
add_compile_definitions(LOG_LEVEL_DEBUG)
add_compile_definitions(LOG_LEVEL_INFO)
add_compile_definitions(LOG_LEVEL_WARN)
add_compile_definitions(LOG_LEVEL_ERROR)
```

for mutex enable

```sh
-DENABLE_LOG_MUTEX
```

```cmake
add_compile_definitions(ENABLE_LOG_MUTEX)
```

```cpp
#define ENABLE_LOG_MUTEX
```

```sh
-DENABLE_LOG_MUTEX
```
