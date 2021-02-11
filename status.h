#ifndef ASSIGNMENT_IMAGE_ROTATION_STATUS_H
#define ASSIGNMENT_IMAGE_ROTATION_STATUS_H
enum openFileStatus {
    OPEN_OK = 0,
    OPEN_INVALID_FILENAME,
    OPEN_ERROR
};

enum closeFileStatus {
    CLOSE_OK = 0,
    CLOSE_ERROR
};
enum readStatus {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER
};
enum writeStatus {
    WRITE_OK = 0,
    WRITE_ERROR
};

#endif //ASSIGNMENT_IMAGE_ROTATION_STATUS_H
