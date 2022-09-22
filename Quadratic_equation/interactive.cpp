#include <assert.h>
#include <stdio.h>
#include <math.h>

void introduction()
{
    printf("              ЭТО ПРОГРАММА ДЛЯ ВЫЧИСЛЕНИЯ КОРНЕЙ КВАДРАТНОГО УРАВНЕНИЯ!\n");
    printf("Для этого нужно ввести три коэффицента квадратного уравнения!\n\n");
    printf("Введите через пробел три коэффицента: ");
} 

void skip_line()
{
    int symbol = 0;

    do {
        symbol = getchar();
    } while (symbol != '\n' && symbol != EOF);
}

void input_coefficients(double *a, double *b, double *c)
{
    assert(a);
    assert(b);
    assert(c);
    
    while(scanf("%lf %lf %lf", a, b, c) != 3)
    {
        skip_line();
        printf("Вы некорректно ввели число!\n");
        printf("Введите через пробел три коэффицента: ");
    }
}
