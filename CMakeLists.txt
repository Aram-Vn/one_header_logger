# CMakeLists.txt (project root)
cmake_minimum_required(VERSION 3.14)
project(my_app)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(logger)

add_executable(my_app main.cpp)
target_link_libraries(my_app PRIVATE logger)

target_compile_definitions(my_app PRIVATE
    ENABLE_LOG_MUTEX
)

# If not Visual Studio generator, copy compile_commands.json
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