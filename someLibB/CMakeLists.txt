# SPDX-License-Identifier: Apache-2.0
cmake_minimum_required(VERSION 3.20.0)

set(namespace "someLibB")
project(someLibB VERSION 3.0.0 LANGUAGES CXX)


add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/someLibB.cpp
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
    include/someLibB.hpp
)



### Fetching someLibA
## If you want to have a custom path, set the variable below
# set(CMAKE_PREFIX_PATH "/usr/lib/local")
find_package(someLibA 1.0.9 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE someLibA::someLibA)





# where to find our CMake modules
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Installing)
