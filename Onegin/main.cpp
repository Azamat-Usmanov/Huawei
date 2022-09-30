#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include "evgeniy_onegin.h" // TODO: write your includes before system ones to avoid implicit dependencies
#include "my_sort.h"


int main()
{
    FILE *f, *f1; // TODO: Why did you split declaration and assignment?
    f = fopen("verse.txt", "r");
    f1 = fopen("result.txt", "w"); // TODO: You're opening file just to immediately close it
    fclose(f1);
    
    char * text = NULL; // TODO: move closer to usage
    // TODO: Also, I see, for now you're avoiding russian text, e.g. you made "Hamlet", not "Onegin"
    //       Are you planing on extending this to work with russian characters? (It's part of the task)

    LINE_OF_TEXT * buffStruct = NULL;
    // TODO:       ^~~~~~~~~~ fix naming, eugeniy_onegin.cpp for detailed explanations

    int number_of_symbols = counting_number_of_symbols("verse.txt");
    // TODO: Do you really need to open this file twice ^~~~~~~~~
    //       (first time you did at the beginning of main, and second
    //        is inside of "counting_number_of_symbols)

    int number_of_lines = create_buffer(f, &text, number_of_symbols);
    filling_array_of_structures(&buffStruct, text, number_of_symbols, number_of_lines);
    fclose(f); // TODO: Check errno (check create_buffer in eugeniy_onegin.cpp for more details)

    my_qsort(buffStruct, 0, number_of_lines - 1, comparator_for_first_words);
    write_in_file(buffStruct, number_of_lines, "result.txt");
    // TODO: Do not reopen file every time:     ^~~~~~~~~~

    my_qsort(buffStruct, 0, number_of_lines - 1, comparator_for_last_words);
    write_in_file(buffStruct, number_of_lines, "result.txt");
    // TODO: Do not reopen file every time:     ^~~~~~~~~~

    write_original_text_in_text(number_of_symbols, text, "result.txt");
    // TODO: Do not reopen file every time:               ^~~~~~~~~~

    free(buffStruct);
    free(text);
    return 0;
}
