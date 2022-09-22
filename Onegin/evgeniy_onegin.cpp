#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evgeniy_onegin.h"
#include <sys/stat.h>
#include <ctype.h>

int comparator_for_first_words(const void * a_ptr, const void * b_ptr)
{
    const char * a = (const char*)a_ptr;
    const char * b = (const char*)b_ptr;
    int i = 0;
    int j = 0;

    if (isalpha(*(a + i)))
        if (isalpha(*(b + j))) 
            while ((tolower(*(a + i)) - tolower(*(b + j))) == 0)
            {
                i++;
                j++;
            }
        else
            j++;
    else
        i++;
    
    return tolower(*(a + i)) - tolower(*(b + j));
}

int comparator_for_last_words(const void * a_ptr, const void * b_ptr)
{
    const char * a = (const char*)a_ptr;
    const char * b = (const char*)b_ptr;
    int i = 0;
    int j = 0;

    while (*(a + i) != '\0')
        i++;

    while (*(b + j) != '\0')
        j++;

    for (int k = 0; k < i; k++) {
        if (isalpha(*(a + i - 1))) 
            if (isalpha(*(b + j - 1))) 
                while ((tolower(*(a + i - 1)) - tolower(*(b + j - 1))) == 0) 
                {
                    i--;
                    j--;
                }
            else 
                j--;
        else 
            i--;
    }
    return tolower(*(a + i - 1)) - tolower(*(b + j - 1));
}

void my_qsort(LINE_OF_TEXT * buffStruct, int left, int right, int (*comparator)(const void * a_ptr, const void * b_ptr))
{
    int i, last;
    void swap(LINE_OF_TEXT * buffStruct1, int i, int j);
    if (left >= right)
        return; 
    swap(buffStruct, left, (left + right)/2);
    last = left;
    for(i = left+1; i <= right; i++) {
        if (comparator(buffStruct[i].str_pointer, buffStruct[left].str_pointer) < 0) 
            swap(buffStruct, ++last, i);
    }
    swap(buffStruct, left, last);
    my_qsort(buffStruct, left, last-1, comparator);
    my_qsort(buffStruct, last+1, right, comparator);
}

void swap(LINE_OF_TEXT * buffStruct, int i, int j)
{
    LINE_OF_TEXT temp = buffStruct[i];
    buffStruct[i] = buffStruct[j];
    buffStruct[j] = temp;
}

int counting_number_of_symbols(const char * file_name) // todo file name
{
    struct stat buff;
    stat(file_name, &buff);
    int symbols = buff.st_size;
    return symbols;
}

int string_parsing(FILE *f, char **text, int number_of_symbols)
{
    *text = (char*)calloc((number_of_symbols + 1), sizeof(char));
    fread(*text, sizeof(char), number_of_symbols, f);

    int number_of_lines = 0;

    for (int i = 0; i < number_of_symbols; i++) 
    {
        while((*text)[i] != '\n' && (*text)[i] != '\0') 
            i++;
        (*text)[i] = '\0';
        number_of_lines++;
    }

    return number_of_lines;
}

void filling_array_of_structures(LINE_OF_TEXT ** buffStruct, char ** text, int number_of_symbols, int number_of_lines)
{
    *buffStruct = (LINE_OF_TEXT*)calloc(number_of_lines, sizeof(LINE_OF_TEXT));
    number_of_lines = 0;
    int count = 0;
    for (int i = 0; i < number_of_symbols; i++)
    {
        (*buffStruct)[number_of_lines].str_pointer = &(*text)[i];
        while ((*text)[i] != '\n' && (*text)[i] != '\0')
            i++;
        (*buffStruct)[number_of_lines].len = i - count;
        number_of_lines++;
        count = i;
    }
}
