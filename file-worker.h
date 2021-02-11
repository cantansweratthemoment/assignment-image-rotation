#ifndef ASSIGNMENT_IMAGE_ROTATION_FILE_WORKER_H
#define ASSIGNMENT_IMAGE_ROTATION_FILE_WORKER_H

#include "stdio.h"
#include "status.h"
#include "inttypes.h"
#include "image.h"
#include "bmp-worker.h"

enum openFileStatus openFile(char const *name, struct image *image);

enum closeFileStatus closeFile(char const *name, struct image *image);

#endif //ASSIGNMENT_IMAGE_ROTATION_FILE_WORKER_H
