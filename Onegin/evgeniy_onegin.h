#ifndef EVGENIY_ONEGIN_SRC_H_
#define EVGENIY_ONEGIN_SRC_H_
#include <stdio.h>

typedef struct line_of_text_
{
    char *str_pointer;
    int len;
} LINE_OF_TEXT;


int counting_number_of_symbols(const char * file_name);
int create_buffer(FILE *f, char ** text, int number_of_symbols);
void filling_array_of_structures(LINE_OF_TEXT ** buffStruct, char * text, int number_of_symbols, int number_of_lines);
void write_in_file(LINE_OF_TEXT * buffStruct, int number_of_lines, const char * name_file);
void write_original_text_in_text(int number_of_symbols, char * text, const char * name_file);

#endif  // EVGENIY_ONEGIN_SRC_H_