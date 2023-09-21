#include "complex.h"
#include <stdlib.h>
#include <stdbool.h>
#include "parse_number_string.h"
#include <stdio.h>
#include "error_handling.h"

ComplexNum add(ComplexNum in1, ComplexNum in2, enum Result* result) {
    ComplexNum output;

    output.real = in1.real + in2.real;
    output.imaginary = in1.imaginary + in2.imaginary;

    *result = SUCESS;
    return output;
}

ComplexNum sub(ComplexNum in1, ComplexNum in2, enum Result* result) {
    ComplexNum output;

    output.real = in1.real - in2.real;
    output.imaginary = in1.imaginary - in2.imaginary;

    *result = SUCESS;
    return output;
}

ComplexNum mult(ComplexNum in1, ComplexNum in2, enum Result* result) {
    ComplexNum output;

    output.real = in1.real * in2.real - in1.imaginary * in2.imaginary;
    output.imaginary = in1.real * in2.imaginary + in2.real * in1.imaginary;

    *result = SUCESS;
    return output;
}

ComplexNum divide(ComplexNum in1, ComplexNum in2, enum Result* result) {
    ComplexNum output;

    if (!((in2.real * in2.real + in2.imaginary * in2.imaginary) > 0) && !((in2.real * in2.real + in2.imaginary * in2.imaginary) < 0)) {
    
        output.real = 0;
        output.imaginary = 0;
        *result = DIVISION_BY_ZERO;
        return output;
    }

    output.real = (in1.real * in2.real + in1.imaginary * in2.imaginary) 
                / (in2.real * in2.real + in2.imaginary * in2.imaginary);
    
    output.imaginary = (in1.imaginary * in2.real - in1.real * in2.imaginary) 
                     / (in2.real * in2.real + in2.imaginary * in2.imaginary);

    *result = SUCESS;
    return output;
}

ComplexNum createComplexNum(double real, double imaginary) {
    ComplexNum newComplexNum;

    newComplexNum.real = real;
    newComplexNum.imaginary = imaginary;

    return newComplexNum;
}