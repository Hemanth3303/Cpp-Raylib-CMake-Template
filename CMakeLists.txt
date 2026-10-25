cmake_minimum_required(VERSION 3.26)
project("Cpp-Raylib-CMake-Template" LANGUAGES C CXX)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Game)

include(cmake/base/core/core.cmake)
include(cmake/base/utils/print_vars.cmake)

print_var(CMAKE_BUILD_TYPE)
print_var(CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
print_var(CMAKE_LIBRARY_OUTPUT_DIRECTORY)
print_var(CMAKE_RUNTIME_OUTPUT_DIRECTORY)
print_var(CMAKE_INSTALL_PREFIX)

add_subdirectory("vendor/raylib")
add_subdirectory("Game")
