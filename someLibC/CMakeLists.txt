# SPDX-License-Identifier: Apache-2.0
cmake_minimum_required(VERSION 3.20.0)

# Set the project workspace, it's used as a reference for the installed filesðð
set(PROJECT_WORKSPACE
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
    CACHE PATH "Project workspace"
)

set(namespace "someLibC")
project(someLibC VERSION 5.0.0 LANGUAGES CXX)

## headerOnlyLib info
set(headerOnlyLib_NAME   libShape)
set(headerOnlyLib_VERSION   0.5.0)
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_WORKSPACE}/.project_libraries/cmake/${headerOnlyLib_NAME}-${headerOnlyLib_VERSION}")
find_package(${headerOnlyLib_NAME} ${headerOnlyLib_VERSION} CONFIG REQUIRED)

## someLibB info
set(someLibB_NAME   someLibB)
set(someLibB_VERSION   3.0.0)
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_WORKSPACE}/.project_libraries/cmake/${someLibB_NAME}-${someLibB_VERSION}")
find_package(${someLibB_NAME} ${someLibB_VERSION} CONFIG REQUIRED)

add_library(${PROJECT_NAME} STATIC)

target_link_libraries(${PROJECT_NAME} PRIVATE libShape::libShape)
target_link_libraries(${PROJECT_NAME} PRIVATE someLibB::someLibB)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/someLibC.cpp
)

# Specify include directories for the target
target_include_directories(${PROJECT_NAME}
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# without it public headers won't get installed
set(public_headers
    include/someLibC.hpp
)

# where to find our CMake modules
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Installing)
