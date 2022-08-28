#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "kvadratka.h"

int main()
{
    system("clear");
    double a, b, c;

    introduction();

    if (verification(&a, &b, &c)) 
    {
        output_roots(a, b, c);
    }

    return 0;
}

void introduction()
{
    printf("              ЭТО ПРОГРАММА ДЛЯ ВЫЧИСЛЕНИЯ КОРНЕЙ КВАДРАТНОГО УРАВНЕИНИЯ!\n");
    printf("Для этого нужно ввести три коэффицента квадратного уравнения!\n\n");
}

int input_coefficient(double *a, double *b, double *c)
{
    char k;

    printf("Первый коэффицент: ");
    if (scanf("%lf%c", a, &k) != 2 || k != '\n')
    {
        return 0;
    }
    
    printf("Второй коэффицент: ");
    if (scanf("%lf%c", b, &k) != 2 || k != '\n')
    {
        return 1;
    }

    printf("Третий коэффицент: ");
    if (scanf("%lf%c", c, &k) != 2 || k != '\n')
    {
        return 2;
    }

    return 3;
}

int verification(double *a, double *b, double *c)
{
    int check = input_coefficient(a, b, c);
    
    if (check == 0)
    {
        input_error();
    }
    else if (check == 1)
    {
        input_error();
    }
    else if (check == 2)
    {
        input_error();
    }
    else
    {
        return 1;
    }

    return 0;
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

void output_roots(double a, double b, double c)
{
    printf("\nОтвет:\n");
    if (a == 0 && b != 0)
    {
        double x = linear_equation(b, c);

        printf("Корень уравнения: %lf\n", x);
    }
    else if (a == 0 && b == 0)
    {
        printf("У этого уравнения нет корней!\n");
    }
    else
    {
        double d = discriminant(a, b, c);
        double x1 = first_root(d, a, b);
        double x2 = second_root(d, a, b);

        if (d > 0) 
        {
            printf("Первый корень: %lf\n", x1);
            printf("Второй корень: %lf\n", x2);
        }
        else if (d == 0)
        {
            printf("Один корень уравнения: %lf\n", x1);
        }
        else
        {
            printf("У этого уравнения нет корней!\n");
        }
    }
}

void input_error()
{
    printf("Вы некорректно ввели число!\n");
}
