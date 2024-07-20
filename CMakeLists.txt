cmake_minimum_required(VERSION 3.26)

project("Cpp-Raylib-Game-Template" LANGUAGES C CXX)

# Set the available build configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "Limited Configs" FORCE)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Application)

include(cmake/print.cmake)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif()

if(MSVC)
	add_compile_options(/EHsc)
endif()

print(CMAKE_BUILD_TYPE)

# Use the generator expression $<0:> so that the specified folder is used directly, without any configuration-dependent suffix.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/$<0:>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/$<0:>")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/$<0:>")

print(CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
print(CMAKE_LIBRARY_OUTPUT_DIRECTORY)
print(CMAKE_RUNTIME_OUTPUT_DIRECTORY)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
SET(USE_MSVC_RUNTIME_LIBRARY_DLL OFF CACHE BOOL "" FORCE)

add_subdirectory("vendor/raylib")
add_subdirectory("Game")