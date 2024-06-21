# SPDX-License-Identifier: Apache-2.0
cmake_minimum_required(VERSION 3.20.0)

set(namespace "libShape")
project(libShape VERSION 0.5.0 LANGUAGES CXX)

# Set the project workspace, it's used as a reference for the installed files
set(PROJECT_WORKSPACE
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
    CACHE PATH "Project workspace"
)

add_library(${PROJECT_NAME} INTERFACE)

# Specify include directories for the target
target_include_directories(${PROJECT_NAME}
    INTERFACE
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# without it public headers won't get installed
set(public_headers
    include/someLibShape.hpp
)

# where to find our CMake modules
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Installing)
