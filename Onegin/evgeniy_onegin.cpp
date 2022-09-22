#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evgeniy_onegin.h"
#include <sys/stat.h>
#include <ctype.h>
#include <assert.h>

int comparator_for_first_words(const void * a_ptr, const void * b_ptr)
{
    assert(a_ptr);
    assert(b_ptr);

    const LINE_OF_TEXT * a = (const LINE_OF_TEXT *)a_ptr;
    const LINE_OF_TEXT * b = (const LINE_OF_TEXT *)b_ptr;
    int i = 0;
    int j = 0;
    if (isalpha(*(a->str_pointer + i)))
    {
        if (isalpha(*(b->str_pointer + j)))
        {
            while ((tolower(*(a->str_pointer + i)) - tolower(*(b->str_pointer + j))) == 0)
            {
                i++;
                j++;
            }
        }
        else
            j++;
    }
    else
        i++;

    return tolower(*(a->str_pointer + i)) - tolower(*(b->str_pointer + j));
}

int comparator_for_last_words(const void * a_ptr, const void * b_ptr)
{
    assert(a_ptr);
    assert(b_ptr);

    const LINE_OF_TEXT * a = (const LINE_OF_TEXT *)a_ptr;
    const LINE_OF_TEXT * b = (const LINE_OF_TEXT *)b_ptr;
    
    int a_len = a->len;
    int b_len = b->len;

    for (int i = 0; i < a->len; i++)
    {
        if (isalpha(*(a->str_pointer + a_len - 1)))
        {
            if (isalpha(*(b->str_pointer + b_len - 1)))
            {
                while ((tolower(*(a->str_pointer + a_len - 1)) - tolower(*(b->str_pointer + b_len - 1))) == 0)
                {
                    a_len--;
                    b_len--;   
                }
            }
            else
                b_len--;
        } 
        else
            a_len--;
    }
    return tolower(*(a->str_pointer + a_len - 1)) - tolower(*(b->str_pointer + b_len - 1));
}

void my_qsort(LINE_OF_TEXT * buffStruct, int left, int right, int (*comparator)(const void * a_ptr, const void * b_ptr))
{
    assert(buffStruct);
    assert(comparator);

    int i, last;
    void swap(LINE_OF_TEXT * buffStruct, int i, int j);
    if (left >= right)
        return; 
    swap(buffStruct, left, (left + right)/2);
    last = left;
    for(i = left+1; i <= right; i++) {
        if (comparator(&buffStruct[i], &buffStruct[left]) < 0) 
            swap(buffStruct, ++last, i);
    }
    swap(buffStruct, left, last);
    my_qsort(buffStruct, left, last-1, comparator);
    my_qsort(buffStruct, last+1, right, comparator);
}

void swap(LINE_OF_TEXT * buffStruct, int i, int j)
{
    assert(buffStruct);

    LINE_OF_TEXT temp = buffStruct[i];
    buffStruct[i] = buffStruct[j];
    buffStruct[j] = temp;
}

int counting_number_of_symbols(const char * file_name)
{
    assert(file_name);

    struct stat buff;
    stat(file_name, &buff);
    int symbols = buff.st_size;
    return symbols;
}

int creat_buffer(FILE *f, char ** text, int number_of_symbols)
{
    *text = (char*)calloc((number_of_symbols + 2), sizeof(char));
    
    assert(text);

    fread(*text, sizeof(char), number_of_symbols, f);

    int number_of_lines = 0;

    for (int i = 0; i < number_of_symbols; i++) 
    {
        while((*text)[i] != '\n' && (*text)[i] != '\0') 
            i++;
        number_of_lines++;
    }
    (*text)[number_of_symbols] = '\n';
    return number_of_lines;
}

void filling_array_of_structures(LINE_OF_TEXT ** buffStruct, char ** text, int number_of_symbols, int number_of_lines)
{
    *buffStruct = (LINE_OF_TEXT*)calloc(number_of_lines, sizeof(LINE_OF_TEXT));

    assert(*text);
    assert(*buffStruct);

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

void write_in_file(FILE *f, LINE_OF_TEXT * buffStruct, int number_of_lines, const char * name_file)
{
    assert(buffStruct);
    assert(name_file);

    f = fopen(name_file, "a");
    for (int i = 0; i < number_of_lines; i++) 
    {
        fwrite(buffStruct[i].str_pointer, sizeof(char), buffStruct[i].len, f);
    }
    fputc('\n', f);
    fputc('\n', f);
    fclose(f);
}

void write_original_text_in_text(FILE *f, int number_of_symbols, char * text, const char * name_file)
{
    assert(text);
    assert(name_file);

    f = fopen(name_file, "a");
    fwrite(text, sizeof(char), number_of_symbols, f);
    fclose(f);
}
