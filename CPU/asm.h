#ifndef SRC_ASM_H_
#define SRC_ASM_H_

#include "enum.h"
#include "../Onegin/evgeniy_onegin.h"
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Stack/Stack.h"

#define MAX_LEN_CMD 10
#define LEN_LABLES 4048

#define DEF_CMD(name, num, arg, codd) \
    if (strcmp(cmd, #name) == 0) \
    { \
        code[ip++] = num; \
        if (arg) GetArgs(&buffStruct[i], code, &ip, lables); \
    } \
    else \

typedef struct
{
    char * SIGNATURA;
    int VERSION;
    int NUMBER_OF_COMMANDS;
} INFO;

void compile(const char * file_name);
void GetArgs(line_of_text * buffStruct, int * code, int * ip, int * lables);

#endif  // SRC_ASM_H_