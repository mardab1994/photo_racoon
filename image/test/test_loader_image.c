#include "image/image.h"
#include "image/loader.h"
#include "image/saver.h"

#include <string.h>

static int
test(image_t *image)
{
    const char *input_filename  = "../../image/test/input_test.pgm";
    const char *output_filename = "output_test.pgm";

    if (image_set_input_filename(image, input_filename)) {
        return -1;
    }

    if (image_set_output_filename(image, output_filename)) {
        return -2;
    }

    if (image_loader(image)) {
        return -3;
    }

    if (image->width != 6 || image->height != 5 || image->grayscale != 120 || strncmp(image->format.magic_number, "P2", strlen("P2"))) {
        return -4;
    }

    for (int i = 0; i < (image->width * image->height); i++) {
        if (image->pixels[i] != 120) {
            return -5;    
        }
    }

    return 0;
}

int
main(void)
{
    image_t image = {0};

    int result = test(&image);

    image_free(&image);

    return result;
}