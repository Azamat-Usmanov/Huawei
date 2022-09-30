#include "Stack.h"
#include "Verification.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    Stack stk1 = {};
    StackCtor(&stk1, 5);
    StackPush(&stk1, 1);
    StackPush(&stk1, 2);
    StackPush(&stk1, 3);
    StackPush(&stk1, 4);
    StackPop(&stk1);
    StackPop(&stk1);
    // StackPush(&stk1, 2);
    for (size_t i = 0; i < stk1.capacity; i++) {
        printf(ELEM_FORMAT, stk1.data[i]);
    }
    StackDestroy(&stk1);
    // StackDestroy(&stk1);
    return 0;
} 