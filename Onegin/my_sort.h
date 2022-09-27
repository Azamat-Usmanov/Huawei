#ifndef SRC_MY_SORT_H_
#define SRC_MY_SORT_H_
#include "evgeniy_onegin.h"

int comparator_for_first_words(const void * a_ptr, const void * b_ptr);
int comparator_for_last_words(const void * a_ptr, const void * b_ptr);
void my_qsort(LINE_OF_TEXT * buffStruct, int left, int right, int (*comparator)(const void * a_ptr, const void * b_ptr));


#endif  // SRC_MY_SORT_H_