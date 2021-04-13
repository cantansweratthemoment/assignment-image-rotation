#include "file-worker.h"
#include "logger.h"

enum openFileStatus openFile(char const *name, struct image *image) {
    if (!name) {
        return OPEN_INVALID_FILENAME;
    }
    FILE *in = fopen(name, "rb");
    if (!in) {
        return OPEN_ERROR;
    }
    enum readStatus readStatus = fromBmp(in, image);
    if (readStatus != READ_OK) {
        return OPEN_ERROR;
    } else {
        return OPEN_OK;
    }
    return OPEN_OK;
}

enum closeFileStatus closeFile(char const *name, struct image *image) {
    FILE *out = fopen(name, "wb");
    if (!out) {
        return CLOSE_ERROR;
    }
    enum writeStatus writeStatus = toBmp(out, image);
    fclose(out);
    if (writeStatus != WRITE_OK) {
        return CLOSE_ERROR;
    }
    return CLOSE_OK;
}
