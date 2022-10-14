#ifndef EVGENIY_ONEGIN_SRC_H_
#define EVGENIY_ONEGIN_SRC_H_
#include <stdio.h>

typedef struct
{
    char *str_pointer;
    int len;
} line_of_text;

int count_number_of_symbols(const char * file_name);
void create_buffer(char ** text, int number_of_symbols);
void fill_poem_struct(line_of_text ** buffStruct, char * text, int number_of_symbols, int number_of_lines);
void write_in_file_sorted_poem(line_of_text * line_buffer, int number_of_lines, FILE *file_to_write);
void write_buffer_to_file(int number_of_symbols, char * text, FILE *file_to_write);
int text_reading(char * text);
int line_count(char ** text, int number_of_symbols);

#endif  // EVGENIY_ONEGIN_SRC_H_
