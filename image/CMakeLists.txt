add_library(image
            loader.h loader.c
            saver.h saver.c
            image.h image.c
            formats.h formats.c)

add_subdirectory(test)

enable_testing()

add_test(NAME test_image_set_filenames COMMAND test/test_image_set_filenames)
add_test(NAME test_loader_image COMMAND test/test_loader_image)
