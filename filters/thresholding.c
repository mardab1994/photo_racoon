#include "filters.h"

#include <stdlib.h>

int
filters_thresholding(image_t *const image, const int threshold)
{
    if ((image == NULL) || (image->pixels == NULL)) {
        return -1;
    }

    if (threshold > image->grayscale) {
        return -2;
    }

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            if (image->pixels[i * image->width + j] <= threshold) {
                image->pixels[i * image->width + j] = 0;
            } else {
                image->pixels[i * image->width + j] = image->grayscale;
            }
        }
    }

    return 0;
}

int
filters_half_thresholding_black(image_t *const image, const int threshold)
{
    if ((image == NULL) || (image->pixels == NULL)) {
        return -1;
    }

    if (threshold > image->grayscale) {
        return -2;
    }

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            if (image->pixels[i * image->width + j] <= threshold) {
                image->pixels[i * image->width + j] = 0;
            }
        }
    }

    return 0;
}

int
filters_half_thresholding_white(image_t *const image, const int threshold)
{
    if ((image == NULL) || (image->pixels == NULL)) {
        return -1;
    }

    if (threshold > image->grayscale) {
        return -2;
    }

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            if (image->pixels[i * image->width + j] > threshold) {
                image->pixels[i * image->width + j] = image->grayscale;
            }
        }
    }

    return 0;
}