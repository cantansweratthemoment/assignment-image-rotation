#include <stdbool.h>
#include "bmp-worker.h"
#include "logger.h"
#include "header.h"

enum writeStatus toBmp(FILE *out, struct image const *img) {
    if (!out) {
        return WRITE_ERROR;
    }
    struct bmpHeader header = {0};
    setHeader(&header, img->width, img->height);
    if (fwrite(&header, sizeof(struct bmpHeader), 1, out) != 1) {
        return WRITE_ERROR;
    }
    uint32_t const padding = ((4 - (img->width * 3 % 4)) % 4);
    uint8_t const paddingValue = 0;
    for (uint64_t i = 0; i < img->height; i++) {
        if (fwrite(&img->data[i * img->width], sizeof(struct pixel), img->width, out) != img->width) {
            return WRITE_ERROR;
        }
        fwrite(&paddingValue, 1, padding, out);
    }
    return WRITE_OK;
}

enum readStatus fromBmp(FILE *in, struct image *img) {
    struct bmpHeader header = {0};
    if (!checkHeader(&header, in)) {
        return READ_INVALID_HEADER;
    }
    *img = createImage(header.biWidth, header.biHeight);
    uint32_t padding = ((4 - (img->width * 3 % 4)) % 4);
    for (uint64_t i = 0; i < img->height; i++) {
        if (fread(&img->data[i * img->width], sizeof(struct pixel), img->width, in) != img->width) {
            return READ_INVALID_BITS;
        }
        fseek(in, padding, SEEK_CUR);
    }
    return READ_OK;
}
