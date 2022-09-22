#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include "evgeniy_onegin.h"


int main()
{
    FILE *f;
    f = fopen("verse.txt", "r");

    char * text;
    LINE_OF_TEXT * buffStruct;

    int number_of_symbols = counting_number_of_symbols("verse.txt");
    int number_of_lines = string_parsing(f, &text, number_of_symbols);
    filling_array_of_structures(&buffStruct, &text, number_of_symbols, number_of_lines);

    my_qsort(buffStruct, 0, number_of_lines - 1, comparator_for_first_words);
    write_in_file(f, buffStruct, number_of_lines, "result.txt");

    my_qsort(buffStruct, 0, number_of_lines - 1, comparator_for_last_words);
    write_in_file(f, buffStruct, number_of_lines, "result.txt");

    write_original_text_in_text(f, number_of_symbols, text, "result.txt");

    fclose(f);
    free(buffStruct);
    free(text);
    return 0;
}