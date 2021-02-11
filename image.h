#ifndef ASSIGNMENT_IMAGE_ROTATION_IMAGE_H
#define ASSIGNMENT_IMAGE_ROTATION_IMAGE_H

#include <inttypes.h>

struct pixel {
    uint8_t b, g, r;
};

struct image {
    uint64_t width, height;
    struct pixel *data;
};

struct image createImage(uint16_t, uint16_t);

void destroyImage(struct image *);

struct image rotateImage(const struct image);

#endif //ASSIGNMENT_IMAGE_ROTATION_IMAGE_H
