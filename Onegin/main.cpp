#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include "evgeniy_onegin.h"
#include "my_sort.h"


int main()
{
    FILE *f, *f1;
    f = fopen("verse.txt", "r");
    f1 = fopen("result.txt", "w");
    fclose(f1);
    
    char * text = NULL;
    LINE_OF_TEXT * buffStruct = NULL;

    int number_of_symbols = counting_number_of_symbols("verse.txt");

    int number_of_lines = create_buffer(f, &text, number_of_symbols);
    filling_array_of_structures(&buffStruct, text, number_of_symbols, number_of_lines);
    fclose(f);

    my_qsort(buffStruct, 0, number_of_lines - 1, comparator_for_first_words);
    write_in_file(buffStruct, number_of_lines, "result.txt");

    my_qsort(buffStruct, 0, number_of_lines - 1, comparator_for_last_words);
    write_in_file(buffStruct, number_of_lines, "result.txt");

    write_original_text_in_text(number_of_symbols, text, "result.txt");

    free(buffStruct);
    free(text);
    return 0;
}