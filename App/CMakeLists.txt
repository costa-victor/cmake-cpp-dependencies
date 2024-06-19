cmake_minimum_required(VERSION 3.20)

project(app VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_PREFIX_PATH "/path/to/someLibrary/install")
set(CMAKE_PREFIX_PATH "/Users/costav10/cmake-study/library_dependencies/.install")
find_package(someLibB 1.0.9 CONFIG REQUIRED)
find_package(someLibB 3.0.0 CONFIG REQUIRED)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE someLibB::someLibB)