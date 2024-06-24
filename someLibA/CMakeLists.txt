# SPDX-License-Identifier: Apache-2.0
cmake_minimum_required(VERSION 3.20.0)

set(namespace "someLibA")
project(someLibA VERSION 1.0.9 LANGUAGES CXX)

# Set the project workspace, it's used as a reference for the installed files
set(PROJECT_WORKSPACE
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
    CACHE PATH "Project workspace"
)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/someLibA.cpp
        src/internalLib.cpp
)

# Specify include directories for the target
target_include_directories(${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${PROJECT_NAME}-${PROJECT_VERSION}/include/${PROJECT_NAME}>
)

# without it public headers won't get installed
set(public_headers
    include/someLibA.hpp
)

# where to find our CMake modules
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Installing)
