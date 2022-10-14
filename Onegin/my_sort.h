#ifndef SRC_MY_SORT_H_
#define SRC_MY_SORT_H_
#include "evgeniy_onegin.h"

enum SORT_FLAG {FORWARD = 1, BACK = -1};

int my_strcmp(char * a_ptr, char * b_ptr, int sorted);
int comparator_for_first_words(const void * a_ptr, const void * b_ptr);
int comparator_for_last_words(const void * a_ptr, const void * b_ptr);
void swap(void * elem_to_swap, int i, int j, size_t size);
void my_qsort(line_of_text * buffStruct, int left, int right, int (*comparator)(const void * a_ptr, const void * b_ptr));


#endif  // SRC_MY_SORT_H_