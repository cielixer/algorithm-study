# CMake Version
cmake_minimum_required(VERSION 3.10)

# Project Declaration
project(CXX_TEMPLATE VERSION 1.0)

# Variables
set(PROJECT_ROOT ${PROJECT_SOURCE_DIR})

# Modern CXX Configuration
set(CMAKE_CXX_STANDARD 17)
set(LINKER_LANGUAGE "CXX")
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Architecture settings
set(x64 OFF)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(x64 ON)
endif()

# Build type
if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

# make executable
add_executable(app.out main.cpp)