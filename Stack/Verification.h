#ifndef SRC_VERIFICATION_H_
#define SRC_VERIFICATION_H_
#include "Stack.h"

void FindErrors(Stack * stk);
int Verification(Stack * stk);
void WriteErrorsInLogfile(FILE *file_err);
void WriteElementsInLogfile(FILE *file_stack, Stack * stk);
void WriteChangesInLogfile_(const char * pretty_function, const char * file, int line, Elem_t value);

#endif  // SRC_VERIFICATION_H_