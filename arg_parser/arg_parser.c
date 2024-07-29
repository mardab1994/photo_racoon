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
    printf("\t --threshold val \r\n");

    printf("\t --black-threshold val  \r\n");
    printf("\t --white-threshold val  \r\n");

    printf("\t --gamma val  \r\n");
    printf("\t --level black_level white_level  \r\n");
}

int
arg_parser(const int argc, const char *argv[])
{
    if (argv == NULL) {
        arg_parser_help();
        return -1;
    }


    bool has_filter = false;
    bool has_in     = false;
    bool has_out    = false;

    int    threshold = -1;
    int    black     = -1;
    int    white     = -1;
    double gamma;

    for (int i = 1; i < argc; i++) {
        if (!has_in && (strcmp(argv[i], "--in") == 0) && (i + 1 <= argc)) {
            has_in = true;
            continue;
        }

        if (!has_out && (strcmp(argv[i], "--out") == 0) && (i + 1 <= argc)) {
            has_out = true;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--negative") == 0)) {
            has_filter = true;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--threshold") == 0) && (i + 1 <= argc) && (sscanf(argv[i + 1], "%d", &threshold) == 1)) {
            has_filter = true;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--black-threshold") == 0) && (i + 1 <= argc) && (sscanf(argv[i + 1], "%d", &black) == 1)) {
            has_filter = true;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--white-threshold") == 0) && (i + 1 <= argc) && (sscanf(argv[i + 1], "%d", &white) == 1)) {
            has_filter = true;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--gamma") == 0) && (i + 1 <= argc) && (sscanf(argv[i + 1], "%lf", &gamma) == 1)) {
            has_filter = true;
            continue;
        }

        if (!has_filter && (strcmp(argv[i], "--level") == 0) && (i + 2 <= argc) && (sscanf(argv[i + 1], "%d", &black) == 1) &&
            (sscanf(argv[i + 2], "%d", &white) == 1)) {
            has_filter = true;
            continue;
        }
    }

    if (!has_in || !has_out || !has_filter) {
        arg_parser_help();
        return -2;
    }

    return 0;
}