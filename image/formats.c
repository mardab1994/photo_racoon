#include "formats.h"

#include <string.h>

static const format_params_t format_params[] = {
    {.format = FORMAT_NONE, .magic_number = "unsupported"},
    { .format = PBM_P1,     .magic_number = "P1", .max_greyscale = 1, .max_values_in_single_line = 70, .supported = true},
    { .format = PBM_P4,     .magic_number = "P4", .max_greyscale = 1, .max_values_in_single_line = 70, .supported = true}, /// < Binary P1

    { .format = PGM_P2,     .magic_number = "P2", .max_greyscale = 255,   .max_values_in_single_line = 70, .supported = true},
    { .format = PGM_P5,     .magic_number = "P5", .max_greyscale = 65535, .max_values_in_single_line = 70, .supported = true}, ///< Binary P2

    { .format = PPM_P3,     .magic_number = "P3", .max_greyscale = 255,   .max_values_in_single_line = 70, .supported = true},
    { .format = PPM_P6,     .magic_number = "P6", .max_greyscale = 65535, .max_values_in_single_line = 70, .supported = true}, ///< Binary P3
};

format_params_t
format_check(const char *in)
{
    format_t format = FORMAT_NONE;

    for (; format < FORMAT_LAST; format++) {
        if (memcmp(in, format_params[format].magic_number, strlen(format_params[format].magic_number)) == 0) {
            return format_params[format];
        }
    }

    return format_params[FORMAT_NONE];
}