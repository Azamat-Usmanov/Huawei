#include "evgeniy_onegin.h"
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
