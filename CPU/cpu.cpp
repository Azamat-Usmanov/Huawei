#include "cpu.h"

int GetArg(int * code, int * ip)
{
    if (code[*ip] >= 9 && code[*ip] <= 15)
    {
        *ip = code[(*ip) + 1];
    }
    else
    {
        int value = code[(*ip) + 1];
        (*ip)++;
        return value;
    }
}

void printCode(int * code, int * ip)
{
    for (int i = 0; i < *ip; i++)
    {
        printf("%02d %02d\n", i, code[i]);
    }
}

void Run(const char * file_name)
{
    FILE *binary_file = fopen(file_name, "rb");
    INFO info;
    fread(&info, sizeof(INFO), 1, binary_file);

    fseek(binary_file, 16, SEEK_SET);

    int * code = (int*)calloc(info.NUMBER_OF_COMMANDS, sizeof(int));

    fread(code, sizeof(int), info.NUMBER_OF_COMMANDS, binary_file);

    fclose(binary_file);

    Stack stk1 = {};
    StackCtor(&stk1, 10);

    int ip = 0;

    while (code[ip] != 0)
    {
        // printf("%d\n", ip);
        switch (code[ip])
        {
            #include "cmd.h"
            default:
                break;
        }
    }

    // printCode(code, &ip);
}