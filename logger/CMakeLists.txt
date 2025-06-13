cmake_minimum_required(VERSION 3.14)
project(logger LANGUAGES CXX)

add_library(logger INTERFACE)

target_include_directories(logger INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Allow user to define logging threshold and mutex at compile time
target_compile_definitions(logger INTERFACE
    $<$<BOOL:${LOG_LEVEL_THRESHOLD}>:LOG_LEVEL_THRESHOLD=${LOG_LEVEL_THRESHOLD}>
    $<$<BOOL:${ENABLE_LOG_MUTEX}>:ENABLE_LOG_MUTEX>
)

# default threshold if none is set
if (NOT DEFINED LOG_LEVEL_THRESHOLD)
    target_compile_definitions(logger INTERFACE LOG_LEVEL_THRESHOLD=LOG_LEVEL_DEBUG)
endif()
