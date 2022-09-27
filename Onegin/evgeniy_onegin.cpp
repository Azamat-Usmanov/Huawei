#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evgeniy_onegin.h"
#include <sys/stat.h>
#include <ctype.h>
#include <assert.h>


int counting_number_of_symbols(const char * file_name)
{
    assert(file_name);

    struct stat buff;
    stat(file_name, &buff);
    int symbols = buff.st_size;
    return symbols;
}

int create_buffer(FILE *f, char ** text, int number_of_symbols)
{
    assert(text);

    *text = (char*)calloc((number_of_symbols + 2), sizeof(char));
    
    assert(*text);

    fread(*text, sizeof(char), number_of_symbols, f);

    int number_of_lines = 0;

    for (int i = 0; i < number_of_symbols; i++) 
    {
        while((*text)[i] != '\n' && (*text)[i] != '\0') 
            i++;
        number_of_lines++;
    }
    (*text)[number_of_symbols] = '\n';

    return number_of_lines;
}

void filling_array_of_structures(LINE_OF_TEXT ** buffStruct, char * text, int number_of_symbols, int number_of_lines)
{
    assert(buffStruct);
    *buffStruct = (LINE_OF_TEXT*)calloc(number_of_lines, sizeof(LINE_OF_TEXT));

    assert(text);
    assert(*buffStruct);

    number_of_lines = 0;
    int count = 0;
    for (int i = 0; i < number_of_symbols; i++)
    {
        (*buffStruct)[number_of_lines].str_pointer = text + i;
        while (text[i] != '\n' && text[i] != '\0')
            i++;
        (*buffStruct)[number_of_lines].len = i - count;
        number_of_lines++;
        count = i;
    }
}

void write_in_file(LINE_OF_TEXT * buffStruct, int number_of_lines, const char * name_file)
{
    assert(buffStruct);
    assert(name_file);

    FILE *f;
    f = fopen(name_file, "a");

    for (int i = 0; i < number_of_lines; i++) 
    {
        fwrite(buffStruct[i].str_pointer, sizeof(char), buffStruct[i].len, f);
    }
    fputc('\n', f);
    fputc('\n', f);

    fclose(f);
}

void write_original_text_in_text(int number_of_symbols, char * text, const char * name_file)
{
    assert(text);
    assert(name_file);
    FILE *f;
    f = fopen(name_file, "a");
    fwrite(text, sizeof(char), number_of_symbols, f);
    fclose(f);
}
