#ifndef KVADRATKA_SRC_H_
#define KVADRATKA_SRC_H_

void introduction();
void input_coefficient(double*, double*, double*);
int check_pointer(double*, double*, double*, double*, double*, double*);
double first_root(double, double, double);
double second_root(double, double, double);
double discriminant(double, double, double);
double linear_equation(double, double);
int number_of_solutions(double, double, double, double);
int calculation(double*, double*, double*, double*, double, double, double);
void input_error();
void pointer_error();
void output(int, double, double, double);
int is_zero(double);

#endif  // KVADRATKA_SRC_H_
