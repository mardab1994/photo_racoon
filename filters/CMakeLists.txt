add_library(filters
            filters.h
            negative.c
            thresholding.c
            gamma.c
            levels.c)

include_directories(${CMAKE_SOURCE_DIR})
target_link_libraries(filters image)

find_library(MATH_LIBRARY m)
target_link_libraries(filters m)
