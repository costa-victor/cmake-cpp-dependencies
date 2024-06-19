# SPDX-License-Identifier: Apache-2.0
cmake_minimum_required(VERSION 3.20.0)

set(namespace "someLibA")
project(someLibA VERSION 1.0.9 LANGUAGES CXX)


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
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# without it public headers won't get installed
set(public_headers
    include/someLibA.hpp
)

add_custom_target(graphviz ALL
    COMMAND ${CMAKE_COMMAND} "--graphviz=foo.dot" .
    COMMAND dot -Tpng foo.dot -o foo.png
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# where to find our CMake modules
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
#message(STATUS "CMake module path: ${CMAKE_MODULE_PATH}")
include(Installing)
