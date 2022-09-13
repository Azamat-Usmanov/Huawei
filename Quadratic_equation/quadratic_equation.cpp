#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "quadratic_equation.h"

static int is_zero(double x)
{
    const double EPS = 1e-7;
    return fabs(x) < EPS;
}

static double calculate_discriminant(double a, double b, double c)
{
    return pow(b, 2) - 4 * a * c;
}

SOLUTIONS solve_linear_equation(double *x, double b, double c) 
{
    assert(x);

    if (is_zero(b) && !is_zero(c))
    { 
        return no_root;
    }
    
    if (is_zero(b) && is_zero(c))
    {
        return infinit_number_of_roots;
    }
    
    *x = -c / b;
    return one_root;
}

SOLUTIONS solve_quadratic_equation(double *x1, double *x2, double a, double b, double c)
{
    assert(x1);
    assert(x2);
    assert(x1 != x2);

    if (is_zero(a))
    {
        return solve_linear_equation(x1, b, c);
    }

    double discriminant = calculate_discriminant(a, b, c);

    *x1 = (-b + sqrt(discriminant)) / (2 * a);
    *x2 = (-b - sqrt(discriminant)) / (2 * a);

    if (discriminant > 0)
    {
        return two_root;
    }
    
    if (is_zero(discriminant))
    {
        return one_root;
    }

    return no_root;
}

void print_equation_solution(SOLUTIONS number_of_roots, double x1, double x2)
{
    switch (number_of_roots)
    {
    case no_root:
        printf("У этого уравнения нет коренй!\n");
        break;
    case one_root:
        printf("Один корень уравнения: %lf\n", x1);
        break;
    case two_root:
        printf("Первый корень: %lf\n", x1);
        printf("Второй корень: %lf\n", x2);
        break;
    case infinit_number_of_roots:
        printf("Бесконечно много корней!\n");
        break;
    default:
        assert(0);
        break;
    }
}
