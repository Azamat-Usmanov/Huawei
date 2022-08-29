#include <stdio.h>
#include <math.h>
#include "kvadratka.h"

#define EPS 1e-7

void introduction()
{
    printf("              ЭТО ПРОГРАММА ДЛЯ ВЫЧИСЛЕНИЯ КОРНЕЙ КВАДРАТНОГО УРАВНЕИНИЯ!\n");
    printf("Для этого нужно ввести три коэффицента квадратного уравнения!\n\n");
}

void input_coefficient(double *a, double *b, double *c)
{
    while(scanf("%lf %lf %lf", a, b, c) != 3)
    {
        while (getchar() != '\n');
        printf("Вы некорректно ввели число!\n");
        printf("Введите через пробел три коэффицента: ");
    }
}

double first_root(double d, double a, double b)
{
    return (-b + sqrt(d)) / (2 * a);
}

double second_root(double d, double a, double b)
{
    return (-b - sqrt(d)) / (2 * a);
}

double discriminant(double a, double b, double c)
{
    return pow(b, 2) - 4 * a * c;
}

double linear_equation(double b, double c) {
    return -c / b;
}

int check_pointer(double *a, double *b, double *c, double *dis, double *x1, double *x2)
{
    return a || b || c || dis || x1 || x2;
}

int calculation(double *dis, double *x1, double *x2, double *lin_eq, double a, double b, double c)
{
    *dis = discriminant(a, b, c);
    
    if (is_zero(a) && !is_zero(b))
    {
        *lin_eq = linear_equation(b, c);
        return 3;
    }
    else if (!is_zero(a))
    {
        if (*dis > 0)
        {
            *x1 = first_root(*dis, a, b);
            *x2 = second_root(*dis, a, b);
            return 2;
        }
        else if (is_zero(*dis))
        {
            *x1 = first_root(*dis, a, b);
            return 1;
        }
    }

    return 0;
}

void pointer_error()
{
    printf("Указатель равен нулю!\n");
}

void output(int num, double x1, double x2, double lin_eq)
{
    switch (num)
    {
    case 0:
        printf("У этого уравнения нет коренй!\n");
        break;
    case 1:
        printf("Один корень уравнения: %lf\n", x1);
        break;
    case 2:
        printf("Первый корень: %lf\n", x1);
        printf("Второй корень: %lf\n", x2);
        break;
    case 3:
        printf("Линейный корень уравнения: %lf\n", lin_eq);
    default:
        break;
    }
}

int is_zero(double x)
{
    return fabs(x) < EPS;
}
