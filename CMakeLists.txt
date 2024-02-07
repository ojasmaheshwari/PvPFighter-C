cmake_minimum_required(VERSION 3.25.2)

set(CMAKE_CXX_STANDARD 17)

project(PvPFighter VERSION 0.0.1)

set (SOURCES src/main.c)

set(CMAKE_BUILD_TYPE Debug)

find_package(SDL2 REQUIRED)
include_directories(PvPFighter ${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_image) 
