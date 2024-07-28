#include "loader.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define LOADER_IMAGE_LINE_SIZE (1024)

static char line[LOADER_IMAGE_LINE_SIZE];

static int
check_image_format(FILE *fptr, const image_t *image)
{
    if ((fptr == NULL) || (image == NULL)) {
        return -1;
    }

    if (fgets(line, sizeof(line), fptr) == NULL) {
        return -2;
    }

    if ((line[0] == 'P') || (line[1] == '2')) {
        printf("PGM format\r\n");
    }

    char c;

    do {
        c = fgetc(fptr);
        printf("read char %c \r\n", c);
        if (c == '#') {
            char *result = fgets(line, sizeof(line), fptr);
            if (result == NULL) {
                break;
            }
        } else {
            ungetc(c, fptr);
            break;
        }

    } while (c == '#');

    return 0;
}

static int
check_image_size(FILE *fptr, image_t *const image)
{
    if ((fptr == NULL) || (image == NULL)) {
        return -1;
    }

    if (fscanf(fptr, "%u %u %d", &image->width, &image->height, &image->grayscale) != 3) {
        return -2;
    }

    printf("Image size: %u x %u px\r\n", image->width, image->height);
    printf("Image grayscale = %d\r\n", image->grayscale);

    return 0;
}

static int
read_image(FILE *fptr, const image_t *const image)
{
    if ((fptr == NULL) || (image == NULL)) {
        return -1;
    }

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int val;
            if (fscanf(fptr, "%d", &val) != 1) {
                return -2;
            }
            printf("%d ", val);
        }
        printf("\r\n");
    }

    return 0;
}

int
image_loader(const char *filename, image_t *const image)
{
    if ((filename == NULL) || (image == NULL)) {
        return -1;
    }

    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL) {
        return -2;
    }

    int result = check_image_format(fptr, image);
    if (result) {
        return result;
    }

    result = check_image_size(fptr, image);
    if (result) {
        return result;
    }

    result = read_image(fptr, image);

    fclose(fptr);

    return 0;
}
