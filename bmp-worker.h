#ifndef ASSIGNMENT_IMAGE_ROTATION_BMP_WORKER_H
#define ASSIGNMENT_IMAGE_ROTATION_BMP_WORKER_H

#include "status.h"
#include <stdio.h>
#include "inttypes.h"
#include "image.h"

enum readStatus fromBmp(FILE *in, struct image *img);

enum writeStatus toBmp(FILE *out, struct image const *img);

struct __attribute__((packed)) bmpHeader {
    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};

static void setHeader(struct bmpHeader *, int64_t, int64_t);

#endif //ASSIGNMENT_IMAGE_ROTATION_BMP_WORKER_H
