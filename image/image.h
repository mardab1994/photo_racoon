#pragma once

#include <stdint.h>

typedef struct {
    char    *filename;
    char    *magic_number_str;
    char    *file_extension;
    uint32_t width;
    uint32_t height;
    int  grayscale;
} image_t;
