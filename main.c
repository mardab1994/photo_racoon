#include <stdio.h>

#include "image/image.h"
#include "image/loader.h"
#include "image/saver.h"

#include "arg_parser/arg_parser.h"
#include "filters/filters.h"

int
main(int argc, const char *argv[])
{
    image_t image = {0};
    filter_t filter;

    if (arg_parser(argc, argv, &image, &filter)) {
        image_free(&image);
        return -1;
    }

    int result = image_loader(&image);
    image_show_input(&image);

    if (filter.has_negative) {
        filters_negative(&image);
    } else if (filter.has_negative) {
        filters_thresholding(&image, filter.threshold);
    } else if (filter.has_negative) {
        filters_half_thresholding_black(&image, filter.black);
    } else if (filter.has_negative) {
        filters_half_thresholding_white(&image, filter.white);
    } else if (filter.has_negative) {
        filters_gamma(&image, filter.gamma);
    } else if (filter.has_negative) {
        filters_levels(&image, filter.black, filter.white);
    } else {
        printf("No filter\r\n");
    }

    image_saver(&image);
    image_show_output(&image);
    image_free(&image);

    return result;
}
