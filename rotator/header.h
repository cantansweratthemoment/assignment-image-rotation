#ifndef ASSIGNMENT_IMAGE_ROTATION_HEADER_H
#define ASSIGNMENT_IMAGE_ROTATION_HEADER_H
#include <stdbool.h>
#include "inttypes.h"
#include <stdio.h>
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

void setHeader(struct bmpHeader *header, int64_t width, int64_t height);

bool checkHeader(struct bmpHeader *, FILE *);
#endif //ASSIGNMENT_IMAGE_ROTATION_HEADER_H
