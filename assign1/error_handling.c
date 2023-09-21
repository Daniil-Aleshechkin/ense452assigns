#include "error_handling.h"
#include <stdio.h>
#include <stdlib.h>

const char* INVALID_INPUT_ERROR = "5: invalid input";
const char* TOO_MANY_ARGS_ERROR = "3: extra arguments";
const char* TOO_FEW_ARGS_ERROR = "2: missing arguments";
const char* DIVISION_BY_ZERO_ERROR = "4: divide by zero";
const char* UNKNOWN_ERROR = "6: unknown error";
const char* UNSUPPORTED_OPPERATION_ERROR = "1: illegal command";

void printResult(enum Result result) {
    switch (result)
    {
    case SUCESS:
        break;
    case TOO_MANY_ARGS:
        fprintf(stdout, "error code: %s", TOO_MANY_ARGS_ERROR);
        break;
    case TOO_FEW_ARGS:
        fprintf(stdout, "error code: %s", TOO_FEW_ARGS_ERROR);
        break;
    case DIVISION_BY_ZERO:
        fprintf(stdout, "error code: %s", DIVISION_BY_ZERO_ERROR);
        break;
    case UNSUPPORTED_OPPERATION:
        fprintf(stdout, "error code: %s", UNSUPPORTED_OPPERATION_ERROR);
        break;
    case INVALID_INPUT:
        fprintf(stdout, "error code: %s", INVALID_INPUT_ERROR);
        break;
    case UNKNOWN:
        fprintf(stdout, "error code: %s", UNKNOWN_ERROR);
        break;
    default:
        break;
    }
}
