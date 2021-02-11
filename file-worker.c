#include "file-worker.h"
#include "logger.h"

enum openFileStatus openFile(char const *name, struct image *image) {
    if (!name) {
        printerr("Ошибка открытия файла - INVALID_FILENAME.\n");
        return OPEN_INVALID_FILENAME;
    }
    FILE *in = fopen(name, "rb");
    if (!in) {
        printerr("Ошибка открытия файла.\n");
        return OPEN_ERROR;
    }
    enum readStatus readStatus = fromBmp(in, image);
    if (readStatus != READ_OK) {
        printerr("Ошибка открытия файла.\n");
        return OPEN_ERROR;
    } else {
        print("Успешное открытие файла.\n");
        return OPEN_OK;
    }
    return OPEN_OK;
}

enum closeFileStatus closeFile(char const *name, struct image *image) {
    FILE *out = fopen(name, "wb");
    if (!out) {
        printerr("Ошибка записи в файл.\n");
        return CLOSE_ERROR;
    }
    enum writeStatus writeStatus = toBmp(out, image);
    fclose(out);
    if (writeStatus != WRITE_OK) {
        printerr("Ошибка записи в файл.\n");
        return CLOSE_ERROR;
    }
    print("Успешная запись в файл.\n");
    return CLOSE_OK;
}
