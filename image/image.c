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

    if (image->input_filename != NULL) {
        free(image->input_filename);
        image->input_filename = NULL;
    }

    if (image->output_filename != NULL) {
        free(image->output_filename);
        image->output_filename = NULL;
    }

    return 0;
}

int
image_show(image_t *const image)
{
    if (image == NULL) {
        return -1;
    }

    if (image->input_filename == NULL) {
        return -2;
    }

    size_t len     = strlen("display ") + strlen(image->input_filename) + strlen(" &") + 1;
    char  *command = malloc(len);

    if (command == NULL) {
        return -3;
    }

    snprintf(command, len, "%s %s &", "display", image->input_filename);

    system(command);

    free(command);

    return 0;
}

static char *
image_set_filename(const char *source_filename)
{
    if (source_filename == NULL) {
        return NULL;
    }

    char *destination_filename = NULL;

    size_t filename_len  = strlen(source_filename) + 1;
    destination_filename = malloc(filename_len);
    if (destination_filename == NULL) {
        return NULL;
    }

    snprintf(destination_filename, filename_len, "%s", source_filename);

    return destination_filename;
}

int
image_set_input_filename(image_t *image, const char *filename)
{
    image->input_filename = image_set_filename(filename);
    return image->input_filename != NULL ? 0 : -1;
}

int
image_set_output_filename(image_t *image, const char *filename)
{
    image->output_filename = image_set_filename(filename);
    return image->output_filename != NULL ? 0 : -1;
}
