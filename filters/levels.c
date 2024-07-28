#include "filters.h"

#include <stdlib.h>

int
filters_levels(image_t *const image, uint8_t black, uint8_t white)
{
    if ((image == NULL) || (image->pixels == NULL)) {
        return -1;
    }

    black = (black * image->grayscale) / 100;
    white = (white * image->grayscale) / 100;

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            if (image->pixels[i * image->width + j] <= black) {
                image->pixels[i * image->width + j] = 0;
            } else if ((image->pixels[i * image->width + j] > black) && (image->pixels[i * image->width + j] < white)) {
                image->pixels[i * image->width + j] = (image->pixels[i * image->width + j] - black) * ((image->grayscale) / black - white);
            } else if (image->pixels[i * image->width + j] >= white) {
                image->pixels[i * image->width + j] = image->grayscale;
            }
        }
    }

    return 0;
}