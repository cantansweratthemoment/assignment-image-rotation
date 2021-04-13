#ifndef ASSIGNMENT_IMAGE_ROTATION_BMP_WORKER_H
#define ASSIGNMENT_IMAGE_ROTATION_BMP_WORKER_H

#include "status.h"
#include <stdio.h>
#include "inttypes.h"
#include "image.h"
#include "header.h"

enum readStatus fromBmp(FILE *in, struct image *img);

enum writeStatus toBmp(FILE *out, struct image const *img);

#endif //ASSIGNMENT_IMAGE_ROTATION_BMP_WORKER_H
