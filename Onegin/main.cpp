#include "evgeniy_onegin.h"
#include "my_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>


int main()
{   
    int number_of_symbols = count_number_of_symbols("verse.txt");

    char * text = NULL;
    create_buffer(&text, number_of_symbols);

    int number_of_lines = line_count(&text, number_of_symbols);

    line_of_text * line_buffer = NULL;
    fill_poem_struct(&line_buffer, text, number_of_symbols, number_of_lines);

    FILE *file_to_write = fopen("result.txt", "a");
    
    if (!ferror(file_to_write))
    {
        my_qsort(line_buffer, 0, number_of_lines - 1, comparator_for_first_words);
        write_in_file_sorted_poem(line_buffer, number_of_lines, file_to_write);

        my_qsort(line_buffer, 0, number_of_lines - 1, comparator_for_last_words);
        write_in_file_sorted_poem(line_buffer, number_of_lines, file_to_write);

        write_buffer_to_file(number_of_symbols, text, file_to_write);
    }
    else
    {
        perror("Файл не открылся\n");
        abort();
    }

    free(line_buffer);
    free(text);
    return 0;
}
