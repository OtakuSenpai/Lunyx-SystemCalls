cmake_minimum_required(VERSION 3.0)

project(Luny_SysCalls)

set(CMAKE_CXX_EXTENSIONS 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
include_directories("${PROJECT_SOURCE_DIR}/include")

set(HEADERS "include/ProcessCalls.hpp"
        "include/FileIOCalls.hpp"
        "include/helpers.hpp")
set(SOURCES "src/ProcessCalls.cpp"
        "src/FileIOCalls.cpp"
        "src/helpers.cpp")

add_executable(lunyx "main.cpp" ${SOURCES} ${HEADERS})