DEF_CMD(PUSH, 1, 1,
    {
        StackPush(&stk1, GetArg(code, &ip));
    })

DEF_CMD(ADD, 2, 0, 
    {
        StackPush(&stk1, StackPop(&stk1) + StackPop(&stk1));
    })

DEF_CMD(SUB, 3, 0, 
    {
        StackPush(&stk1, -StackPop(&stk1) + StackPop(&stk1));
    })

DEF_CMD(MUL, 4, 0, 
    {
        StackPush(&stk1, StackPop(&stk1) * StackPop(&stk1));
    })

DEF_CMD(DIV, 5, 0, 
    {
        int a = StackPop(&stk1);
        if (a != 0) 
        { 
            StackPush(&stk1, StackPop(&stk1)/a);
        } else {
            printf("Вы пытаетесь поделить на ноль!!\n");
            abort();
        }
    })

DEF_CMD(OUT, 6, 0, 
    {
        printf("%d\n", stk1.data[stk1.size-1]);
    })

DEF_CMD(IN, 7, 0, 
    {
        int value = 0;
        printf("\n");
        scanf("%d", &value);
        StackPush(&stk1, value);
    })

DEF_CMD(DUP, 8, 0, 
    {
        int value = StackPop(&stk1);
        StackPush(&stk1, value);
        StackPush(&stk1, value);
    })

DEF_CMD(JMP, 9, 2,
    {
        GetArg(code, &ip);
    })

DEF_CMD(JB, 10, 2,
    {
        int a = StackPop(&stk1);
        int b = StackPop(&stk1);
        if (b < a) {
            GetArg(code, &ip);
            StackPush(&stk1, b);
            StackPush(&stk1, a);
        }
    })

DEF_CMD(JBE, 11, 2,
    {
        int a = StackPop(&stk1);
        int b = StackPop(&stk1);
        if (b <= a){
            GetArg(code, &ip);
            StackPush(&stk1, b);
            StackPush(&stk1, a);
        }
    })

DEF_CMD(JA, 12, 2,
    {
        int a = StackPop(&stk1);
        int b = StackPop(&stk1);
        if (b > a) {
            GetArg(code, &ip);
            StackPush(&stk1, b);
            StackPush(&stk1, a);
        }
    })

DEF_CMD(JAE, 13, 2,
    {
        int a = StackPop(&stk1);
        int b = StackPop(&stk1);
        if (b >= a) {
            GetArg(code, &ip);
            StackPush(&stk1, b);
            StackPush(&stk1, a);
        }
    })

DEF_CMD(JE, 14, 2,
    {
        int a = StackPop(&stk1);
        int b = StackPop(&stk1);
        if (b == a) {
            GetArg(code, &ip);
            StackPush(&stk1, b);
            StackPush(&stk1, a);
        }
    })

DEF_CMD(JNE, 15, 2,
    {
        int a = StackPop(&stk1);
        int b = StackPop(&stk1);
        if (b != a) {
            GetArg(code, &ip);
            StackPush(&stk1, b);
            StackPush(&stk1, a);
        }
    })

DEF_CMD(HLT, 0, 0, 
    {
        return;
    })
