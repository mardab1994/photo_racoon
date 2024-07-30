#include "arg_parser.h"

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>
#include <stdio.h>

static void
arg_parser_help(void)
{
    printf("\t --in <filename> setup source file\r\n");
    printf("\t --out <filename> setup output filename\r\n");
    printf("\t --negative\r\n");
    printf("\t --threshold val\r\n");

    printf("\t --black-threshold val\r\n");
    printf("\t --white-threshold val\r\n");

    printf("\t --gamma val\r\n");
    printf("\t --level black_level white_level\r\n");
}

int
arg_parser(const int argc, const char *argv[], image_t *image, filter_t *filter)
{
    if ((argv == NULL) || (image == NULL) || (filter == NULL)) {
        arg_parser_help();
        return -1;
    }

    memset(filter, 0, sizeof(filter_t));

    bool has_filter = false;
    bool has_in     = false;
    bool has_out    = false;

    for (int i = 1; i < argc; i++) {
        if (!has_in && (strcmp(argv[i], "--in") == 0) && (i + 1 <= argc)) {
            has_in = image_set_input_filename(image, argv[i + 1]) == 0;
            continue;
        }

        if (!has_out && (strcmp(argv[i], "--out") == 0) && (i + 1 <= argc)) {
            has_out = image_set_output_filename(image, argv[i + 1]) == 0;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--negative") == 0)) {
            filter->has_negative = true;
            has_filter           = true;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--threshold") == 0) && (i + 1 <= argc) &&
            (sscanf(argv[i + 1], "%d", &filter->threshold) == 1)) {
            filter->has_threshold = true;
            has_filter            = true;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--black-threshold") == 0) && (i + 1 <= argc) &&
            (sscanf(argv[i + 1], "%d", &filter->black) == 1)) {
            filter->has_black_threashold = true;
            has_filter                   = true;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--white-threshold") == 0) && (i + 1 <= argc) &&
            (sscanf(argv[i + 1], "%d", &filter->white) == 1)) {
            filter->has_white_threashold = true;
            has_filter                   = true;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--gamma") == 0) && (i + 1 <= argc) && (sscanf(argv[i + 1], "%lf", &filter->gamma) == 1)) {
            filter->has_gamma = true;
            has_filter        = true;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--level") == 0) && (i + 2 <= argc) && (sscanf(argv[i + 1], "%d", &filter->black) == 1) &&
            (sscanf(argv[i + 2], "%d", &filter->white) == 1)) {
            filter->has_level = true;
            has_filter        = true;
            continue;
        }
    }

    if (!has_in || !has_out || !has_filter) {
        printf("Error: %s%s%s\r\n\r\n",
               has_in ? "" : "\r\n\tno input file",
               has_out ? "" : "\r\n\tno output file ",
               has_filter ? "" : "\r\n\tno filter params");
        arg_parser_help();
        return -2;
    }

    return 0;
}