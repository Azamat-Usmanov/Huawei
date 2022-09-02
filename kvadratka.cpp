#include <stdio.h>
#include <math.h>
#include "kvadratka.h"

#define EPS 1e-7 // TODO: Never use defines for constants in C++, there is superior alternatives

void introduction()
{
    printf("              ЭТО ПРОГРАММА ДЛЯ ВЫЧИСЛЕНИЯ КОРНЕЙ КВАДРАТНОГО УРАВНЕНИЯ!\n");
    printf("Для этого нужно ввести три коэффицента квадратного уравнения!\n\n");
}

void input_coefficient(double *a, double *b, double *c)
{ // TODO:            ^ should be in plural
    while(scanf("%lf %lf %lf", a, b, c) != 3)
    {
        while (getchar() != '\n');
        // TODO: what if input is redirected from file and getchar() returs EOF?
        //       After generalization could be extracted in function.

        printf("Вы некорректно ввели число!\n");
        printf("Введите через пробел три коэффицента: ");
    }
}

// TODO: Splitting in functions in many smaller ones is a good thing,
//       but this is a bit too much!
//
//       It is too specific to be useful outside of your library!
//
//       Because:
//           1. Name is too vague. What does "first" root mean? Nothing,
//              it's just "one of" in an almost random order.
//
//           2. It requires discriminant to be passed in, making it too
//              "low level".
//
//           3. Descriminant should be compared to zero before calling it,
//              as for cases where (D <= 0) it will give invalid result or
//              fail with error (see man sqrt)
// 
//       This is already a sign that it should be in public API (your
//       header file) at least.
// 
//       But I would go one step further, since it so deeply connected
//       with equation solver, I would just inline it there.
//       
//       I know that you're using it twice, but both usage can be easily
//       joined together. See if you can figure it out!
//
// note: still separating too much is better then not separating at all,
//       you just need to develop a better intuition about it!

double first_root(double d, double a, double b)
{ // TODO: naming        ^ avoid single letter names, name like "discriminant"
  //                       would be much more descriptive!
    return (-b + sqrt(d)) / (2 * a);
}

// TODO: same critique applies here (see first_root)
double second_root(double d, double a, double b)
{
    return (-b - sqrt(d)) / (2 * a);
}

// TODO: same critique, even though this function is a bit more useful
//       and convincing than two previous ones.
//
//       At the very least remove it from your header and make static.
//
//       And, yeah, name functions with verbs, because they do stuff!
//       calculate_discriminant would be a much better name!
double discriminant(double a, double b, double c)
{
    return pow(b, 2) - 4 * a * c;
}

// TODO: use verbs in function names! Exempli gratia: solve_*
double linear_equation(double b, double c) {
    return -c / b;
}

// TODO: very generic name suggests signature like
//       bool check_pointer(void* pointer);
//
//       Yet this function performs a very specific task,
//       and should be generalized or/and replaced with asserts
//       in all occurences.
//
//       Use special type "bool" if you wish to return true or
//       false, this gives clarity and a bunch of compiler-enforced
//       goods. Don't miss out!
int check_pointer(double *a, double *b, double *c, double *dis, double *x1, double *x2)
{
    return a || b || c || dis || x1 || x2;
}

// TODO: calculation? What kind of calculation? Improve naming, purpose
//       should be obvious from name.

// TODO: "out" variables are conventionally placed at the end 
int calculation(double *dis, double *x1, double *x2, double *lin_eq, double a, double b, double c)
{ // TODO:                 ^ better naming?                     ^ avoid abbrivations, also
  //                                                              why do you need this at all?
    *dis = discriminant(a, b, c);
    // TODO: does your user really need a disciminant after you gave him solution?
    
    if (is_zero(a) && !is_zero(b))
    {
        *lin_eq = linear_equation(b, c);
        return 3; // TODO: create an enum for the return values!
    }
    else if (!is_zero(a)) // TODO: else after return is considered a bad style by most style guides
    {
        if (*dis > 0)
        {
            *x1 = first_root(*dis, a, b);
            *x2 = second_root(*dis, a, b);
            return 2;
        }
        else if (is_zero(*dis)) // TODO: else after return is considered a bad style by most style guides
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
// TODO:    ^~~~~~~~~~~~~~~~~~~~~ Prefer English for reporting errors!
}

void output(int num, double x1, double x2, double lin_eq)
{ // TODO:      ^~~ a more descriptive naming would be nice
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
        // TODO: Why is this an other state? What makes it different from
        //       case 1: which tells that there's a one solution!
        //      
        //       Consider joining two together!
        printf("Линейный корень уравнения: %lf\n", lin_eq);
    default:
        // TODO: If this code is reached it's a pretty bad programmer
        //       error (there was a num's state that wasn't checked).

        //       And there is a specially utiliy in standard library for
        //       telling programmer about program's invariant violations (like such)
        //       ASAP. They are called asserts, use them (especially here!).
        break;
    }
}

int is_zero(double x)
{
    return fabs(x) < EPS;
}
