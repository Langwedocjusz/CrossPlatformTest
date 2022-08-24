cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(CrossPlatformTest)

add_executable(${PROJECT_NAME} src/main.cpp)

