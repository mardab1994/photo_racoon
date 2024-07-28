#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    FORMAT_NONE,
    PBM_P1 = 0,
    PBM_P4,
    PGM_P2,
    PGM_P5,
    PPM_P3,
    PPM_P6,
    FORMAT_LAST
} format_t;

typedef struct {
    format_t    format;
    const char *magic_number;
    uint32_t    max_greyscale;
    uint32_t    max_values_in_single_line;
    bool        supported; ///< Flag to mark format is supported
} format_params_t;

format_params_t format_check(const char *in);
