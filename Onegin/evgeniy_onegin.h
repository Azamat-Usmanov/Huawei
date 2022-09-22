#ifndef EVGENIY_ONEGIN_SRC_H_
#define EVGENIY_ONEGIN_SRC_H_
#include <stdio.h>

typedef struct line_of_text_
{
    char *str_pointer;
    int len;
} LINE_OF_TEXT;

int comparator_for_first_words(const void * a_ptr, const void * b_ptr);
int comparator_for_last_words(const void * a_ptr, const void * b_ptr);
void my_qsort(LINE_OF_TEXT * buffStruct, int left, int right, int (*comparator)(const void * a_ptr, const void * b_ptr));
int counting_number_of_symbols(const char * file_name);
int string_parsing(FILE *f, char ** text, int number_of_symbols);
void filling_array_of_structures(LINE_OF_TEXT ** buffStruct, char ** text, int number_of_symbols, int number_of_lines);
void write_in_file(FILE *f, LINE_OF_TEXT * buffStruct, int number_of_lines, const char * name_file);
void write_original_text_in_text(FILE *f, int number_of_symbols, char * text, const char * name_file);

#endif  // EVGENIY_ONEGIN_SRC_H_