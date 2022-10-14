#include "evgeniy_onegin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <assert.h>
#include <errno.h>


int count_number_of_symbols(const char * file_name)
{
    if (file_name == NULL)
        perror("Название файла не верно\n");
    assert(file_name);

    struct stat buff;
    if (stat(file_name, &buff) == -1)
        perror("имя файла или path-имя не найдено\n");
    int symbols = buff.st_size;
    return symbols;
}

void create_buffer(char ** text, int number_of_symbols)
{
    assert(text);

    *text = (char*)calloc((number_of_symbols + 2), sizeof(char));
    
    if (*text == NULL)
        perror("Буффер имеет нулевой указатель\n");

    assert(*text);
    
    struct stat file_stat = {};

    FILE *file_to_read = fopen("verse.txt", "r");
    if (!ferror(file_to_read))
    {
        if (fread((*text) + 1, sizeof(char), number_of_symbols, file_to_read) != number_of_symbols)
        {
            perror("Текст не записался в буфер\n");
            abort();
        }
    }
    else
    {
        perror("Файл не открылся\n");
        abort();
    }
    if (fclose(file_to_read) == EOF) 
    {
        perror("Файл не смог закрыться\n");
        abort();
    }
    
    (*text)[0] = '\0';
    (*text)[file_stat.st_size] = '\0';

}

int line_count(char ** text, int number_of_symbols)
{
    int number_of_lines = 0;
    for (int i = 1; i < number_of_symbols + 1; i++) 
    {
        while((*text)[i] != '\n' && (*text)[i] != '\0') 
            i++;
        (*text)[i] = '\0';
        number_of_lines++;
    }
    return number_of_lines;
}

void fill_poem_struct(line_of_text ** line_buffer, char * text, int number_of_symbols, int number_of_lines)
{
    assert(line_buffer);
    *line_buffer = (line_of_text*)calloc(number_of_lines, sizeof(line_of_text));

    if (text == NULL)
        perror("Буффер имеет нулевой указатель\n");
    if (*line_buffer == NULL)
        perror("Массив структур имеет нулевой указаталь\n");

    assert(text);
    assert(*line_buffer);

    int num_of_lines = 0;

    int counter = 0;

    for (int i = 1; i < number_of_symbols + 1; i++)
    {
        (*line_buffer)[num_of_lines].str_pointer = text + i;
        while (text[i] != '\0')
            i++;
        text[i] = '\n';
        (*line_buffer)[num_of_lines].len = i - counter;
        num_of_lines++;
        counter = i;
    }
}

void write_in_file_sorted_poem(line_of_text * line_buffer, int number_of_lines, FILE *file_to_write)
{
    if (line_buffer == NULL)
        perror("Массив структур имеет нулевой указаталь\n");

    assert(line_buffer);

    for (int i = 0; i < number_of_lines; i++) 
    {
        if (fwrite(line_buffer[i].str_pointer, sizeof(char), line_buffer[i].len, file_to_write) != line_buffer[i].len)
        {
            perror("В файл не записалось\n");
            abort();
        }
    }
    fputc('\n', file_to_write);
    fputc('\n', file_to_write);
}

void write_buffer_to_file(int number_of_symbols, char * text, FILE *file_to_write)
{
    if (text == NULL)
        perror("Буффер имеет нулевой указатель\n");
    
    assert(text);

    if (fwrite(text + 1, sizeof(char), number_of_symbols, file_to_write) != number_of_symbols)
    {
        perror("В файл не записалось\n");
        abort();
    }
}
