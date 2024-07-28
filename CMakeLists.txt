cmake_minimum_required(VERSION 3.2)

project(photo_racoon
        VERSION 0.0.3
        LANGUAGES C)

set ( CMAKE_C_FLAGS "-Wall")
set ( CMAKE_C_FLAGS "-pedantic")

add_executable(${CMAKE_PROJECT_NAME} main.c)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(image)
target_link_libraries(${CMAKE_PROJECT_NAME} image)

add_subdirectory(filters)
target_link_libraries(${CMAKE_PROJECT_NAME} filters)

