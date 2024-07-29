add_library(arg_parser
            arg_parser.h arg_parser.c)

include_directories(${CMAKE_SOURCE_DIR})
target_link_libraries(arg_parser image)
target_link_libraries(arg_parser filters)
