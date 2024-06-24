cmake_minimum_required(VERSION 3.20)

project(app VERSION 0.1.0)

# Set the project workspace, it's used as a reference for the installed files
set(PROJECT_WORKSPACE
    "${CMAKE_CURRENT_SOURCE_DIR}/../.."
    CACHE PATH "Project workspace"
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## someLibC info
set(someLibC_NAME   someLibC)
set(someLibC_VERSION   5.0.0)
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_WORKSPACE}/.project_libraries/${someLibC_NAME}-${someLibC_VERSION}/cmake")
find_package(${someLibC_NAME} ${someLibC_VERSION} CONFIG REQUIRED)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE someLibC::someLibC)
