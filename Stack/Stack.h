#ifndef STACK_SRC_H_
#define STACK_SRC_H_

#include <stdio.h>
#include <math.h>

typedef double Elem_t;

enum ResizeFlag{UP = 1, DOWN = -1};

#define INFO(stk) (VarInfo) {&#stk[0] + (#stk[0] == '&'), __PRETTY_FUNCTION__, __FILE__, __LINE__}
#define StackCtor(stk, size) StackCtor_(stk, size, INFO(stk))
#define ELEM_FORMAT "%lf "
#define StackDump(stk) StackDump_(stk, __PRETTY_FUNCTION__, __FILE__, __LINE__)
#define VERIFICATOR(stk) if (!Verification(stk)) StackDump(stk);
#define FLAG(stk) Verification(stk) ? "ok" : "error"
#define WriteChangesInLogfile(line, value) WriteChangesInLogfile_(__PRETTY_FUNCTION__, __FILE__, line, value)
#define StackPush(stk, value) StackPush_(stk, value, __LINE__)
#define StackPop(stk) StackPop_(stk, __LINE__)

#define POISON NAN

typedef struct
{
    const char * name;
    const char * func;
    const char * file;
    int line;
} VarInfo;

typedef struct
{
    // conoree
    Elem_t * data;
    size_t size;
    size_t capacity;
    VarInfo info;
    // hash
} Stack;

int StackCtor_(Stack * stk, int capacity, VarInfo info);
void StackResize(Stack * stk, ResizeFlag flag);
int StackPush_(Stack * stk, Elem_t value, int line);
Elem_t StackPop_(Stack * stk, int line);
void PoisonFilling(Stack * stk);
void StackDestroy(Stack * stk);
void StackDump_(Stack * stk, const char * pretty_function, const char * file, int line);

#endif  // STACK_SRC_H_