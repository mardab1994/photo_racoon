#pragma once

#include <stdint.h>

#include "formats.h"

typedef struct {
    char           *filename;
    char           *magic_number_str;
    char           *file_extension;
    uint32_t        width;
    uint32_t        height;
    int             grayscale;
    format_params_t format;
} image_t;
