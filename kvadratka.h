#ifndef KVADRATKA_SRC_H_
#define KVADRATKA_SRC_H_

// TODO: This file is the heart of your program, it provides core API
//       (solving equations) that other programmers can potentially
//       integrate in their own programs.

//       Yet, for some reason, you are putting here most of interactive
//       and debugging functions. Do not do this! Split this file in 
//       multiple organised by purpose.

//       Make sure interface of every header file stays clean and minimal!

void introduction();
void input_coefficient(double*, double*, double*);
int check_pointer(double*, double*, double*, double*, double*, double*);
double first_root(double, double, double);
double second_root(double, double, double);
double discriminant(double, double, double);
double linear_equation(double, double);
int calculation(double*, double*, double*, double*, double, double, double);
void pointer_error();

// TODO: improve naming, "output" is almost as generic as it gets, yet
//       this function does a very niche thing.

//       Tip: use verbs for function names, ideally from function name
//       it's side effects and purpose should be obvious even without
//       reading documentation and, especially, implementation.

//       For example, a good name would be print_equation_solution
void output(int, double, double, double);
// TODO:       ^       ^       ^       ^
//       Always use argument names in function signatures (THIS APPLIES EVERYWHERE)

int is_zero(double);

#endif  // KVADRATKA_SRC_H_
