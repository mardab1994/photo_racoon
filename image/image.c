#include "image.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
image_allocate(image_t *const image)
{
    if (image == NULL) {
        return -1;
    }

    image->pixels = (uint8_t *)malloc(image->height * image->width);
    if (image->pixels == NULL) {
        return -2;
    }

    return 0;
}

int
image_free(image_t *const image)
{
    if (image == NULL) {
        return -1;
    }

    if (image->pixels != NULL) {
        free(image->pixels);
        image->pixels = NULL;
    }

    if (image->filename != NULL) {
        free(image->filename);
        image->filename = NULL;
    }

    return 0;
}

int
image_show(image_t *const image)
{
    if (image == NULL) {
        return -1;
    }

    if (image->filename == NULL) {
        return -2;
    }

    size_t len     = strlen("display ") + strlen(image->filename) + strlen(" &") + 1;
    char  *command = malloc(len);

    if (command == NULL) {
        return -3;
    }

    snprintf(command, len, "%s %s &", "display", image->filename);

    system(command);

    free(command);

    return 0;
}