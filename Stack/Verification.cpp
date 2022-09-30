#include "Stack.h"

int ErrorArray[4] = {0};

void FindErrors(Stack * stk)
{
    if (stk == NULL)
        ErrorArray[0] = 1;

    if (stk->data == NULL)
        ErrorArray[1] = 1;

    if (stk->capacity < 1)
        ErrorArray[2] = 1;

    if (stk->size > stk->capacity)
        ErrorArray[3] = 1;
}

int Verification(Stack * stk)
{
    FindErrors(stk);
    int counter = 0;
    for (int i = 0; i < 4; i++)
    {
        counter = (ErrorArray[i] == 1) ? counter + 1 : counter;
    }

    if (counter)
    {
        // abort();
        return 0;
    }
    return 1;
}

void WriteChangesInLogfile_(const char * pretty_function, const char * file, int line, Elem_t value)
{
    FILE * file_edit = fopen("log_file.txt", "a");

    fprintf(file_edit, "%s at %s(%d): value: %lf\n", pretty_function, file, line, value);

    fclose(file_edit);
}

void WriteErrorsInLogfile(FILE *file_err)
{
    fprintf(file_err, "\n");

    if (ErrorArray[0])
        fprintf(file_err, "Error: Struct pointer equals null\n");

    if (ErrorArray[1])
        fprintf(file_err, "Error: Data pointer equals null\n");

    if (ErrorArray[2])
        fprintf(file_err, "Error: Capacity less than one\n");

    if (ErrorArray[3])
        fprintf(file_err, "Error: Size greater than capacity\n");

    fprintf(file_err, "\n");
}

void WriteElementsInLogfile(FILE *file_stack, Stack * stk)
{
    for (size_t i = 0; i < stk->capacity; i++)
    {
        if (isnan(stk->data[i])) 
        {
            fprintf(file_stack, "[%lu] = %f\n\t\t", i, stk->data[i]);
        }
        else
            fprintf(file_stack, "*[%lu] = %f\n\t\t", i, stk->data[i]);
    }
    fprintf(file_stack, "\r\t}\n}\n\n");
}
