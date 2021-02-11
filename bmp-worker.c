#include "bmp-worker.h"
#include "logger.h"

 static void setHeader(struct bmpHeader *header, int64_t width, int64_t height) {
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

enum writeStatus toBmp(FILE *out, struct image const *img) {
    if (!out) {
        printerr("Ошибка записи в BMP.\n");
        return WRITE_ERROR;
    }
    struct bmpHeader header = {0};
    setHeader(&header, img->width, img->height);
    if (fwrite(&header, sizeof(struct bmpHeader), 1, out) != 1) {
        printerr("Ошибка записи в BMP.\n");
        return WRITE_ERROR;
    }
    uint32_t padding = ((4 - (img->width * 3 % 4)) % 4);
    uint32_t paddingValue = 0;
    for (uint64_t i = 0; i < img->height; i++) {
        if (fwrite(&img->data[i * img->width], sizeof(struct pixel), img->width, out) != img->width) {
            printerr("Ошибка записи в BMP.\n");
            return WRITE_ERROR;
        }
        fwrite(&paddingValue, 1, padding, out);
    }
    print("Успешная запись в BMP.\n");
    return WRITE_OK;
}

enum readStatus fromBmp(FILE *in, struct image *img) {
    struct bmpHeader header = {0};
    if (fread(&header, sizeof(struct bmpHeader), 1, in) != 1) {
        printerr("Ошибка чтения из BMP - INVALID_HEADER.\n");
        return READ_INVALID_HEADER;
    }
    if (header.bfType != 0x4D42) {
        printerr("Ошибка чтения из BMP - INVALID_SIGNATURE.\n");
        return READ_INVALID_SIGNATURE;
    }
    *img = createImage(header.biWidth, header.biHeight);
    uint32_t padding = ((4 - (img->width * 3 % 4)) % 4);
    for (uint64_t i = 0; i < img->height; i++) {
        if (fread(&img->data[i * img->width], sizeof(struct pixel), img->width, in) != img->width) {
            printerr("Ошибка чтения из BMP - INVALID_BITS.\n");
            return READ_INVALID_BITS;
        }
        fseek(in, padding, SEEK_CUR);
    }
    print("Успешное чтениe из BMP.\n");
    return READ_OK;
}
