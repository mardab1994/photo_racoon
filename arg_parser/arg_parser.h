#pragma once

#include "image/image.h"
#include "filters/filters.h"

int arg_parser(const int argc, const char *argv[], image_t *image, filter_t *filter);
