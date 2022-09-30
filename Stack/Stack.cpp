#include "Stack.h"
#include "Verification.h"
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int StackCtor_(Stack * stk, int capacity, VarInfo info)
{
    stk->data = (Elem_t*)calloc(capacity, sizeof(Elem_t));
    stk->capacity = capacity;
    stk->size = 0;
    stk->info.file = info.file;
    stk->info.func = info.func;
    stk->info.line = info.line;
    stk->info.name = info.name;
    PoisonFilling(stk);
    return Verification(stk);
}

int StackPush_(Stack * stk, Elem_t value, int line)
{
    VERIFICATOR(stk);
    stk->data[stk->size++] = value;
    if (stk->size >= stk->capacity)
    {
        StackResize(stk, UP);
    }
    WriteChangesInLogfile(line, value);
    return Verification(stk);
}

Elem_t StackPop_(Stack * stk, int line)
{
    VERIFICATOR(stk);
    Elem_t value = stk->data[stk->size-1];
    StackResize(stk, DOWN);
    stk->data[--stk->size] = POISON;
    WriteChangesInLogfile(line, value);
    return value;
}

void PoisonFilling(Stack * stk)
{
    for (size_t i = stk->size; i < stk->capacity; i++)
    {
        stk->data[i] = POISON;
    }
    VERIFICATOR(stk);
}

void StackResize(Stack * stk, ResizeFlag flag)
{
    if (flag == UP)
    {
        Elem_t * temp_data = (Elem_t*)realloc(stk->data, stk->capacity * 2 * sizeof(Elem_t));
        stk->data = temp_data;
        stk->capacity = stk->capacity * 2;
        PoisonFilling(stk);
    }
    else
    {
        if ((stk->capacity / 4) >= stk->size)
        {
            stk->data = (Elem_t*)realloc(stk->data, (stk->capacity / 2) * sizeof(Elem_t));
            stk->capacity = stk->capacity / 2;
        }
    }
}

void StackDump_(Stack * stk, const char * pretty_function, const char * file, int line)
{
    FILE *file_dump = fopen("log_file.txt", "a");

    WriteErrorsInLogfile(file_dump);

    fprintf(file_dump, "%s at %s(%d):\nStack[%p](%s) %s at %s at %s(%d)\n{\n\tsize = %lu\n\tcapacity = %lu\n\tdata[%p]\n\t{\n\n\t\t",
    pretty_function, file, line, stk, FLAG(stk), stk->info.name, stk->info.func, stk->info.file,
    stk->info.line, stk->size, stk->capacity, stk->data);

    WriteElementsInLogfile(file_dump, stk);

    abort();
}

void StackDestroy(Stack * stk)
{
    VERIFICATOR(stk);
    free(stk->data);
    stk->capacity = 0;
    stk->size = 0;
    stk->data = NULL;
}
