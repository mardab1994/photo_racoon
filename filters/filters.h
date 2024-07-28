#pragma once

#include "image/image.h"

int filters_negative(image_t * const image);
int filters_thresholding(image_t * const image, const int threshold);
int filters_half_thresholding_black(image_t *const image, const int threshold);
int filters_half_thresholding_white(image_t *const image, const int threshold);
int filters_gamma(image_t *const image, const double gamma);
