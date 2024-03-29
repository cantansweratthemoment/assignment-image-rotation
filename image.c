#include <inttypes.h>
#include "image.h"
#include <stdlib.h>
#include "logger.h"

struct image createImage(uint16_t width, uint16_t height) {
    return (struct image) {.width=width, .height=height, .data = malloc(sizeof(struct pixel) * width * height)};
}

void destroyImage(struct image *image) {
    free(image);
}

struct image rotateImage(const struct image origin) {
    struct pixel *newData = malloc(sizeof(struct pixel) * origin.width * origin.height);
    struct image newImage = {.width = origin.height, .height = origin.width, .data = newData};
    for (uint64_t i = 0; i < origin.height; i++) {
        for (size_t j = 0; j < origin.width; j++) {
            newData[getNewDataAddress(i, j, origin)] = origin.data[getOldDataAddress(i, j, origin)];
        }
    }
    print("Поворачиваем картинку...\n");
    return newImage;
}

size_t getNewDataAddress(size_t i, size_t j, const struct image origin) {
    return (j * origin.height + (origin.height - 1 - i));
}

size_t getOldDataAddress(size_t i, size_t j, const struct image origin) {
    return (i * origin.width + j);
}