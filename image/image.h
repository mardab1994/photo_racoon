#pragma once

#include <stdint.h>

#include "formats.h"

typedef struct {
    char           *input_filename;
    char           *output_filename;
    char           *magic_number_str;
    char           *file_extension;
    uint32_t        width;
    uint32_t        height;
    int             grayscale;
    format_params_t format;
    uint8_t        *pixels;
} image_t;

int image_allocate(image_t *const image);
int image_free(image_t *const image);
int image_show_input(image_t *const image);
int image_show_output(image_t *const image);
int image_set_input_filename(image_t *image, const char *filename);
int image_set_output_filename(image_t *image, const char *filename);

