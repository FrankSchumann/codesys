cmake_minimum_required(VERSION 3.12)

# Set some basic project attributes
project (Codesys
		VERSION 0.0.0.1
		DESCRIPTION "CODESYS plugin")
		
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

file(GLOB SOURCES "src/Plugin.cpp" "src/factory/*.cpp" "src/component/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Create a simple configuration header
configure_file(config.h.in config.h)

# Include the configuration header in the build
#target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}" include)
include_directories("${PROJECT_BINARY_DIR}" include)

message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")