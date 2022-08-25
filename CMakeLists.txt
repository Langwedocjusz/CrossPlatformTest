cmake_minimum_required(VERSION 3.16.3)

#Print selected build type
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

#Build output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#Project name and version
project(CrossPlatformTest)



#Specify CPP standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Build current project as an executable
add_executable(${PROJECT_NAME})

#Add build type dependent preprocessor definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE "DISTRIBUTION_BUILD=$<CONFIG:Distribution>")

#Specify source files
file(GLOB_RECURSE headers src/*.h)
file(GLOB_RECURSE sources src/*.cpp)
target_sources(${PROJECT_NAME} PRIVATE ${headers} ${sources})

#Set current project as Visual Studio start project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

#Also build a submodule
add_subdirectory(vendor/glfw)

#Add include dir of submodule to project's include
target_include_directories(${PROJECT_NAME} PUBLIC vendor/glfw/include)

#Add submodule dir for linking
target_link_directories(${PROJECT_NAME} PRIVATE vendor/glfw/src)

#Link against submodule
target_link_libraries(${PROJECT_NAME} glfw)
