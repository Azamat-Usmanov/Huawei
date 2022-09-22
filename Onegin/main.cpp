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

    for (int i = 0; i < number_of_lines; i++) 
    {
        printf("%s\n", buffStruct[i].str_pointer);
    }

    printf("\n\n");

    my_qsort(buffStruct, 0, number_of_lines - 1, comparator_for_last_words);

    for (int i = 0; i < number_of_lines; i++) 
    {
        printf("%s\n", buffStruct[i].str_pointer);
    }

    fclose(f);

    return 0;
}