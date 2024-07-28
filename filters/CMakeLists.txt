add_library(filters
            filters.h
            negative.c
            thresholding.c)

include_directories(${CMAKE_SOURCE_DIR})
target_link_libraries(filters image)
