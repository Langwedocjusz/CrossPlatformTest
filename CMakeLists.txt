cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(CrossPlatformTest)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(vendor/glfw)

target_include_directories(${PROJECT_NAME} PUBLIC vendor/glfw/include)

target_link_directories(${PROJECT_NAME} PRIVATE vendor/glfw/src)

target_link_libraries(${PROJECT_NAME} glfw)
