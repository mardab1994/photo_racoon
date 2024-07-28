#include "filters.h"

#include <math.h>
#include <stdlib.h>

int
filters_gamma(image_t *const image, const double gamma)
{
    if ((image == NULL) || (image->pixels == NULL)) {
        return -1;
    }

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            double new_value = (double)image->pixels[i * image->width + j] / (double)image->grayscale;
            new_value        = pow(new_value, (double)1 / (double)gamma) * (double)image->grayscale;

            image->pixels[i * image->width + j] = (uint8_t)new_value;
        }
    }

    return 0;
}
