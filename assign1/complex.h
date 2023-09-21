#include <stdlib.h>
#include"error_handling.h"

#ifndef COMPLEX
#define COMPLEX

typedef struct {
    double real;
    double imaginary;
} ComplexNum;

ComplexNum add(ComplexNum, ComplexNum, enum Result*);
ComplexNum sub(ComplexNum, ComplexNum, enum Result*);
ComplexNum mult(ComplexNum, ComplexNum, enum Result*);
ComplexNum divide(ComplexNum, ComplexNum, enum Result*);

ComplexNum createComplexNum(double real, double imaginary);

void printComplexNum(ComplexNum in);

#endif