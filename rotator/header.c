#include "header.h"
#include <stdio.h>
#include <stdbool.h>
#include "image.h"

void setHeader(struct bmpHeader *header, int64_t width, int64_t height) {
    header->bfType = 0x4d42;
    header->bOffBits = sizeof(struct bmpHeader);
    header->bfReserved = 0;
    header->bfileSize = height * (width * sizeof(struct pixel) + width % 4 + sizeof(struct bmpHeader));
    header->biBitCount = 24;
    header->biClrImportant = 0;
    header->biClrUsed = 0;
    header->biCompression = 0;
    header->biHeight = height;
    header->biWidth = width;
    header->biPlanes = 1;
    header->biSize = 40;
    header->biSizeImage = height * (width * sizeof(struct pixel) + width % 4);
    header->biXPelsPerMeter = 0;
    header->biYPelsPerMeter = 0;
}

bool checkHeader(struct bmpHeader *header, FILE *in) {
    if ((fread(header, sizeof(struct bmpHeader), 1, in) != 1) || (header->bfType != 0x4D42)) {
        return false;
    }
    return true;
}
