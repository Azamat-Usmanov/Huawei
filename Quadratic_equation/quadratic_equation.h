#ifndef QUADRATIC_EQUATION_SRC_H_
#define QUADRATIC_EQUATION_SRC_H_

enum SOLUTIONS {no_root, one_root, two_root, infinit_number_of_roots};

SOLUTIONS solve_linear_equation(double *x, double b, double c);
SOLUTIONS solve_quadratic_equation(double *x1, double *x2, double a, double b, double c);
void print_equation_solution(SOLUTIONS number_or_roots, double x1, double x2);

#endif  // QUADRATIC_EQUATION_SRC_H_
