#include "filters.h"

#include <stdlib.h>

int
filters_negative(image_t *const image)
{
    if ((image == NULL) || (image->pixels == NULL)) {
        return -1;
    }

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i * image->width + j] = image->grayscale - image->pixels[i * image->width + j];
        }
    }

    return 0;
}
