#include <stdio.h>
#include "image.h"
#include "status.h"
#include "file-worker.h"
#include "logger.h"

void usage() {
    fprintf(stderr, "Usage: ./rotate SRC_IMG NEW_IMG\n");
}

int main(int argc, char **argv) {
    if (argc != 3) usage();
    if (argc < 3) err("Слишком мало аргументов.\n");
    if (argc > 3) err("Слишком много аргументов. \n");
    struct image image = {0};
    enum openFileStatus open_status = openFile(argv[1], &image);
    if (open_status != OPEN_OK) {
        if (open_status == OPEN_INVALID_FILENAME) {
            printerr("Ошибка открытия файла - INVALID_FILENAME.\n");
        }
        if (open_status == OPEN_ERROR) {
            printerr("Ошибка открытия файла.\n");
        }
        err("Ошибка при чтении из файла!\n");
    }
    struct image rotated_image = {0};
    rotated_image = rotateImage(image);
    enum closeFileStatus save_status = closeFile(argv[2], &rotated_image);
    if (save_status != CLOSE_OK) {
        printerr("Ошибка записи в файл.\n");
        err("Ошибка при чтении из файла!\n");
    }
    return 0;
}
