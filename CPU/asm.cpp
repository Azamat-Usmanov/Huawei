#include "asm.h"

void GetArgs(line_of_text * buffStruct, int * code, int * ip, int * lables)
{
    char * tmp = buffStruct->str_pointer;
    int counter = 0;

    while (tmp[counter] != ' ')
    {
        counter++;
    }

    char lable[MAX_LEN_CMD] = "";
    sscanf(&tmp[counter + 1], "%s", lable);

    if (strchr(lable, ':') != NULL)
    {
        code[(*ip)++] = lables[atoi(lable + 1)];
    }
    else
    {
        int value;
        sscanf(&tmp[counter + 1], "%d", &value);
        code[(*ip)++] = value;
    }
}

void compile(const char * file_name)
{
    char * text = NULL;
    line_of_text * buffStruct = NULL;
    int number_of_symbols = count_number_of_symbols(file_name);
    create_buffer(&text, number_of_symbols, file_name);
    int number_of_lines = line_count(&text, number_of_symbols);
    fill_poem_struct(&buffStruct, text, number_of_symbols, number_of_lines);

    int * code = (int*)calloc(number_of_lines * 2, sizeof(int));

    int * lables = (int*)calloc(LEN_LABLES, sizeof(int));

    int i = 0, ip = 0;
    
    while (number_of_lines != 0)
    {
        char cmd[MAX_LEN_CMD] = "";
        sscanf(buffStruct[i].str_pointer, "%s", cmd);
        if (strchr(cmd, ':') != NULL)
        {
            lables[atoi(cmd)] = ip;
        }
        else
        {
            #include "cmd.h"
            /* else */ printf("Err\n");
        }
        number_of_lines--;
        i++;
    }


    FILE * binary_file = fopen("binary_file.txt", "wb");
    INFO info;
    info.SIGNATURA = "VG";
    info.VERSION = 1;
    info.NUMBER_OF_COMMANDS = ip;
    fwrite(&info, sizeof(INFO), 1, binary_file);
    fwrite(code, sizeof(int), ip, binary_file);
    fclose(binary_file);

    free(lables);
    free(code);
}
