#ifndef PANIC_H
#define PANIC_H

#include "kernel_utils.h"

#define PANIC(msg) kernel_panic(msg, __FILE__, __LINE__)

void kernel_panic(const char* message, const char* file, int line);

#endif
