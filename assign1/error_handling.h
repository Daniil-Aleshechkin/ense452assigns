#include <stdlib.h>

#ifndef ERROR_HANDLING
#define ERROR_HANDLING

enum Result{SUCESS, TOO_MANY_ARGS, TOO_FEW_ARGS, DIVISION_BY_ZERO, UNSUPPORTED_OPPERATION, INVALID_INPUT, UNKNOWN};
void printResult(enum Result);

#endif