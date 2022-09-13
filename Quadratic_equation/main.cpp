#include "quadratic_equation.h"
#include "interactive.h"
#include "test.h"

int main()
{
    #ifdef solve
        introduction();

        double a = 0, b = 0, c = 0;

        input_coefficients(&a, &b, &c);

        double x1 = 0, x2 = 0;

        SOLUTIONS number_or_roots = solve_quadratic_equation(&x1, &x2, a, b, c);
        
        print_equation_solution(number_or_roots, x1, x2);
    #endif
    #ifdef test
        unit_tests();
    #endif
    return 0;
}
