cmake_minimum_required(VERSION 3.26)
project("Cpp-Raylib-CMake-Template" LANGUAGES C CXX)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Game)

include(cmake/base/config.cmake)
include(cmake/base/utils.cmake)

print(CMAKE_BUILD_TYPE)
print(CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
print(CMAKE_LIBRARY_OUTPUT_DIRECTORY)
print(CMAKE_RUNTIME_OUTPUT_DIRECTORY)

add_subdirectory("vendor/raylib")
add_subdirectory("Game")
