#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

_Noreturn void err(const char *msg) {
    va_list args;
    vfprintf(stderr, msg, args);
    exit(1);
}

void printerr(const char *message) {
    va_list args;
    vfprintf(stderr, message, args);
}

void print(const char *message) {
    va_list args;
    vfprintf(stdout, message, args);
}
