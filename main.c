#include <stdio.h>

#include "image/image.h"
#include "image/loader.h"

int
main(int argc, const char *argv[])
{
    if (argc >= 2) {
        image_t image;
        int     result = image_loader(argv[1], &image);
        printf("result %d \r\n", result);
        image_show(&image);
        image_free(&image);
        return result;
    }

    return 0;
}
