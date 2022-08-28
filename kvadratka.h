#ifndef KVADRATKA_SRC_H_
#define KVADRATKA_SRC_H_

void introduction();
int input_coefficient(double*, double*, double*);
int verification(double*, double*, double*);
double first_root(double, double, double);
double second_root(double, double, double);
double discriminant(double, double, double);
double linear_equation(double, double);
void output_roots(double, double, double);
void input_error();

#endif  // KVADRATKA_SRC_H_
