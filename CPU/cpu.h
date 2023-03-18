#ifndef SRC_CPU_H_
#define SRC_CPU_H_

#include "asm.h"

#define DEF_CMD(name, num, arg, codd) \
    case num: \
        codd; \
        if (arg != 2) ip += 1; \
        break; \

int GetArg(int * code, int * ip);
void Run(const char * file_name);
void printCode(int * code, int * ip);

#endif  // SRC_CPU_H_
