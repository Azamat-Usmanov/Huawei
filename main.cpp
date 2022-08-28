#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "kvadratka.h"

#define EPS 1e-7

int main()
{
    system("clear");
    double a = 0, b = 0, c = 0;
    double dis = 0;
    double x1 = 0, x2 = 0;
    double lin_eq = 0;

    introduction();
    
    if (check_pointer(&a, &b, &c, &dis, &x1, &x2))
    {
        printf("Введите через пробел три коэффицента: ");

        input_coefficient(&a, &b, &c);

        int num = calculation(&dis, &x1, &x2, &lin_eq, a, b, c);
        
        output(num, x1, x2, lin_eq);
    }
    else
    {
        pointer_error();
    }
    return 0;
}
