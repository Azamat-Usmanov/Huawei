#include <stdio.h>
#include <math.h>
#include "quadratic_equation.h"
#include "test.h"

void test_quadratic_equation(double a, double b, double c, int test_number_of_roots, double test_x1, double test_x2)
{
    double x1 = 0, x2 = 0;
    solve_quadratic_equation(&x1, &x2, a, b, c);
    if (test_number_of_roots != infinit_number_of_roots)
    {
        if ((x1 == test_x1 && x2 == test_x2) || (x1 == test_x2 && x2 == test_x1))
        {
            printf("It's okey\n");
        }
        else
        {
            printf("Input: %lf %lf %lf\n", a, b, c);
            printf("Function result: \nx1: %lf\nx2: %lf\n", x1, x2);
            printf("Output: \nx1_test: %lf\nx2_test: %lf\n", test_x1, test_x2);
            printf("Fall\n");
        }
    }
    else
    {
        printf("It's okey\n");
    }
}

void unit_tests() 
{
    test_quadratic_equation(1, 2, 1, one_root, -1, -1);
    test_quadratic_equation(1, -5, 4, two_root, 1, 4);
    test_quadratic_equation(0, 0, 0, infinit_number_of_roots, 3, 4);
    test_quadratic_equation(0, 2, 1, one_root, -0.5, 0);
}
