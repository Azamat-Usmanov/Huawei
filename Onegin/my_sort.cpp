#include "evgeniy_onegin.h"
#include "my_sort.h"
#include <ctype.h>
#include <assert.h>
#include <string.h>

static int my_isalpha(const char symbol)
{
    return (isalpha(symbol) || symbol == '\n' || symbol == '\0');
}

int my_strcmp(char * a_ptr, char * b_ptr, int sorted)
{
    if (!my_isalpha(*a_ptr))
    {
        return my_strcmp(a_ptr += sorted, b_ptr, sorted);
    }

    if (!my_isalpha(*b_ptr))
    {
        return my_strcmp(a_ptr, b_ptr += sorted, sorted);
    }

    if ((tolower(*a_ptr) == tolower(*b_ptr)) && !my_isalpha(*a_ptr) && !my_isalpha(*b_ptr))
    {
        return my_strcmp(a_ptr += sorted, b_ptr += sorted, sorted);
    }
    
    return tolower(*a_ptr) - tolower(*b_ptr);

}

int comparator_for_first_words(const void * a_ptr, const void * b_ptr)
{
    const line_of_text * a = (const line_of_text *)a_ptr;
    const line_of_text * b = (const line_of_text *)b_ptr;
    return my_strcmp(a->str_pointer, b->str_pointer, FORWARD);
}

int comparator_for_last_words(const void * a_ptr, const void * b_ptr)
{
    const line_of_text * a = (const line_of_text *)a_ptr;
    const line_of_text * b = (const line_of_text *)b_ptr;

    if (a->len == 0)
    {
        return -1;
    }
    if (b->len == 0)
    {
        return 1;
    }

    char * last_symbol_a = a->str_pointer + a->len - 2;
    char * last_symbol_b = b->str_pointer + b->len - 2;

    return my_strcmp(last_symbol_a, last_symbol_b, BACK);
}

void swap(void * elem_to_swap, int i, int j, size_t size)
{
    void * temp = (char*)calloc(1, size);
    memcpy(temp, (char*)elem_to_swap + i * size, size);
    memcpy((char*)elem_to_swap + i * size, (char*)elem_to_swap + j * size, size);
    memcpy((char*)elem_to_swap + j * size, temp, size);
    free(temp);
}

void my_qsort(line_of_text * buffStruct, int left, int right, int (*comparator)(const void * a_ptr, const void * b_ptr))
{
    assert(buffStruct);
    assert(comparator);

    if (left >= right)
        return; 
    swap(buffStruct, left, (left + right)/2, sizeof(line_of_text));
    int i = 0, last = 0;
    last = left;
    for(i = left+1; i <= right; i++) {
        if (comparator(&buffStruct[i], &buffStruct[left]) < 0) 
            swap(buffStruct, ++last, i, sizeof(line_of_text));
    }
    swap(buffStruct, left, last, sizeof(line_of_text));
    my_qsort(buffStruct, left, last-1, comparator);
    my_qsort(buffStruct, last+1, right, comparator);
}
