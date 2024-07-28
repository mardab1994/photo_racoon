#include "loader.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOADER_IMAGE_LINE_SIZE (1024)

static char line[LOADER_IMAGE_LINE_SIZE];

static int
check_image_format(FILE *fptr, image_t *const image)
{
    if ((fptr == NULL) || (image == NULL)) {
        return -1;
    }

    if (fgets(line, sizeof(line), fptr) == NULL) {
        return -2;
    }

    image->format = format_check(line);

    printf("Format: %s\r\n", image->format.magic_number);

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
check_image_info(FILE *fptr, image_t *const image)
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
read_image_pixels(FILE *fptr, image_t *const image)
{
    if ((fptr == NULL) || (image == NULL)) {
        return -1;
    }

    if (image_allocate(image)) {
        return -2;
    }

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int val;
            if (fscanf(fptr, "%d", &val) != 1) {
                return -3;
            }
            image->pixels[i * image->width + j] = (uint8_t)val;
        }
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

    size_t filename_len = strlen(filename) + 1;

    image->filename = malloc(filename_len);
    if (image->filename == NULL) {
        return -3;
    }

    snprintf(image->filename, filename_len, "%s", filename);

    int result = check_image_format(fptr, image);
    if (result) {
        return result;
    }

    result = check_image_info(fptr, image);
    if (result) {
        return result;
    }

    result = read_image_pixels(fptr, image);

    fclose(fptr);

    return 0;
}
