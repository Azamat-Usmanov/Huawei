#ifndef EVGENIY_ONEGIN_SRC_H_
#define EVGENIY_ONEGIN_SRC_H_
#include <stdio.h>

typedef struct line_of_text_
{
    char *str_pointer;
    int len;
} LINE_OF_TEXT; // TODO: very unusual naming style

// Consider using typedef struct { ... };
// ==> note: anonymous struct   ^ 
//
// And a more conventional name, for example:
// typedef struct {
//     ...
// } line_of_text;

int counting_number_of_symbols(const char * file_name);
//  ^~~~~~~~ TODO: Try to name your functions in imperative
// E.g. count_number_of_symbols(...)
//
// It's a good style, makes code clearer and more consistent

int create_buffer(FILE *f, char ** text, int number_of_symbols);
//                      ^ TODO: C'mon, you can do better. Avoid single character names

void filling_array_of_structures(LINE_OF_TEXT ** buffStruct, char * text, int number_of_symbols, int number_of_lines);
// TODO: Same thing, naming in imperative would be better (but this
// name is bad in general), check .cpp for more information

void write_in_file(LINE_OF_TEXT * buffStruct, int number_of_lines, const char * name_file);
void write_original_text_in_text(int number_of_symbols, char * text, const char * name_file);

#endif  // EVGENIY_ONEGIN_SRC_H_
