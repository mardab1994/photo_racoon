#include "image/image.h"

#include <stdlib.h>
#include <string.h>

static int
test(image_t *image)
{
    char *input_filename  = "in_lena.pgm";
    char *output_filename = "out_lena.pgm";

    if (image_set_input_filename(NULL, NULL) != -1) {
        return -10;
    }

    if (image_set_input_filename(image, NULL) != -1) {
        return -11;
    }

    if (image_set_input_filename(NULL, input_filename) != -1) {
        return -12;
    }

    if (image_set_input_filename(image, input_filename) != 0) {
        return -13;
    }

    if (strncmp(image->input_filename, input_filename, strlen(input_filename))) {
        return -14;
    }

    if (image_set_output_filename(NULL, NULL) != -1) {
        return -20;
    }

    if (image_set_output_filename(image, NULL) != -1) {
        return -21;
    }

    if (image_set_output_filename(NULL, output_filename) != -1) {
        return -22;
    }

    if (image_set_output_filename(image, output_filename) != 0) {
        return -23;
    }

    if (strncmp(image->output_filename, output_filename, strlen(output_filename))) {
        return -24;
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