#pragma once

#include "image/image.h"

typedef struct {
    bool has_negative;
    bool has_threshold;
    bool has_black_threashold;
    bool has_white_threashold;
    bool has_gamma;
    bool has_level;

    int    threshold;
    int    black;
    int    white;
    double gamma;
} filter_t;

int filters_negative(image_t * const image);
int filters_thresholding(image_t * const image, const int threshold);
int filters_half_thresholding_black(image_t *const image, const int threshold);
int filters_half_thresholding_white(image_t *const image, const int threshold);
int filters_gamma(image_t *const image, const double gamma);
int filters_levels(image_t *const image, uint8_t black, uint8_t white);
