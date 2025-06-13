cmake_minimum_required(VERSION 3.14)
project(logger_example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the library from parent (this assumes you run cmake from root)
add_subdirectory(.. one_header_logger_build)

add_executable(logger_example main.cpp)

target_link_libraries(logger_example PRIVATE one_header_logger)

target_compile_definitions(logger_example PRIVATE
    LOG_LEVEL_THRESHOLD=LOG_LEVEL_DEBUG
    ENABLE_LOG_MUTEX
)

if(NOT CMAKE_GENERATOR MATCHES "Visual Studio")
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
        DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
        COMMENT "Copying compile_commands.json..."
    )

    add_custom_target(copy_compile_commands ALL
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
endif()