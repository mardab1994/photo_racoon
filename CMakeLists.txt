cmake_minimum_required(VERSION 3.2)

project(photo_racoon
        VERSION 0.0.1
        LANGUAGES C)

set ( CMAKE_C_FLAGS "-Wall")
set ( CMAKE_C_FLAGS "-pedantic")

add_executable(${CMAKE_PROJECT_NAME} main.c)

add_subdirectory(image)
target_link_libraries(${CMAKE_PROJECT_NAME} image)
