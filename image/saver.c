#include "saver.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
saver_image_format(const image_t *image, FILE *fptr)
{
    if ((image == NULL) || (fptr == NULL)) {
        return -1;
    }

    fprintf(fptr, "%s\r\n", image->format.magic_number);

    return 0;
}

int
saver_image_info(const image_t *image, FILE *fptr)
{
    if ((image == NULL) || (fptr == NULL)) {
        return -1;
    }

    fprintf(fptr, "%d %d\r\n", image->width, image->height);
    fprintf(fptr, "%d\r\n", image->grayscale);

    return 0;
}

int
saver_image_pixels(const image_t *image, FILE *fptr)
{
    if ((image == NULL) || (fptr == NULL) || (image->pixels == NULL)) {
        return -1;
    }

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(fptr, "%d ", image->pixels[i * image->width + j]);

            if (j % image->format.max_values_in_single_line == 0) {
                fprintf(fptr, "\r\n");
            }
        }
    }

    return 0;
}

int
image_saver(image_t *const image)
{
    if (image == NULL) {
        return -1;
    }

    size_t filename_len = strlen("ed_") + strlen(image->filename) + 1;

    char *filename = malloc(filename_len);
    if (filename == NULL) {
        return -2;
    }

    snprintf(filename, filename_len, "ed_%s", image->filename);

    FILE *fptr = fopen(filename, "w");

    if (fptr == NULL) {
        return -2;
    }

    saver_image_format(image, fptr);
    saver_image_info(image, fptr);
    saver_image_pixels(image, fptr);

    fclose(fptr);

    return 0;
}
