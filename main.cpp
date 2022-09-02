#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "kvadratka.h"

#define EPS 1e-7

int main()
{
    system("clear"); // TODO: expensive and platform specific, there's a better way
    double a = 0, b = 0, c = 0;
    double dis = 0;
    double x1 = 0, x2 = 0;
    double lin_eq = 0; // TODO: move variables as close to usage as you possibly can

    introduction();
    
    if (check_pointer(&a, &b, &c, &dis, &x1, &x2))
// TODO: They are never null, trust me... Useless check.
//
//       It's like trying to check if your keyboard exists...
//
//       Of course it does, you're pressing on the buttons
//       in this very moment!
//
//       FYI: &<whatever> is NEVER null.
    {
        printf("Введите через пробел три коэффицента: ");

        input_coefficient(&a, &b, &c);

        int num = calculation(&dis, &x1, &x2, &lin_eq, a, b, c);
        
        output(num, x1, x2, lin_eq);
    }
    else
    {
        pointer_error();
        // TODO: Since that check is always true, this code is unreachable
    }
    return 0;
}
