#include "calculator.h"
#include "error_handling.h"
#include "complex.h"
#include "parse_number_string.h"
#include "io_utils.h"
#include "num_utils.h"
#include <stdio.h>

void printOutput(Calculator* calculator) {
    
    if (calculator->calculationResult == SUCESS) {
        double realPart = calculator->out.real;
        double imaginaryPart = calculator->out.imaginary;
        double absRealPart = absValue(realPart);
        double absImaginaryPart = absValue(imaginaryPart);


        if (realPart < 0 && imaginaryPart < 0) {
            fprintf(stdout, "-%.*f - j %.*f \n", countPrecision(absRealPart), absRealPart, countPrecision(absImaginaryPart), absImaginaryPart);
        } else if (realPart >= 0 && imaginaryPart < 0) {
            fprintf(stdout, "%.*f - j %.*f \n", countPrecision(absRealPart), absRealPart, countPrecision(absImaginaryPart), absImaginaryPart);
        } else if (realPart < 0 && imaginaryPart >= 0){
            fprintf(stdout,"-%.*f + j %.*f \n", countPrecision(absRealPart), absRealPart, countPrecision(absImaginaryPart), absImaginaryPart);
        } else {
            fprintf(stdout,"%.*f + j %.*f \n", countPrecision(absRealPart), absRealPart, countPrecision(absImaginaryPart), absImaginaryPart);
        }
        
    } else {
        printResult(calculator->calculationResult);
    }
    
}

Calculator* createCalculator() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->mode = 'U';

    return calc;
}

void calculate(Calculator* calculator) {
    ComplexNum output; 
    enum Result caclulationResult;
    
    switch (calculator->mode)
    {
    case 'A':
    case 'a':
        output = add(calculator->in1, calculator->in2, &caclulationResult);
        break;
    case 'S':
    case 's':
        output = sub(calculator->in1, calculator->in2, &caclulationResult);
        break;
    case 'M':
    case 'm':
        output = mult(calculator->in1, calculator->in2, &caclulationResult);
        break;
    case 'D':
    case 'd':
        output = divide(calculator->in1, calculator->in2, &caclulationResult);
        break;
    default:
        caclulationResult = UNSUPPORTED_OPPERATION;
        break;
    }

    calculator->calculationResult = caclulationResult;
    calculator->out = output;
}

enum Result readInput(Calculator* calculator) {
    enum Result readResult = SUCESS;

    char** parsedInput = read_args(&readResult);

    if (readResult != SUCESS) {
        return readResult;
    }

    for (int i = 1; i < 5; i++) {
        if (!validateNumberString(parsedInput[i])) {
            return INVALID_INPUT;
        }
    }

    calculator->mode = parsedInput[0][0];
    calculator->in1 = createComplexNum(parse_number(parsedInput[1]), parse_number(parsedInput[2]));
    calculator->in2 = createComplexNum(parse_number(parsedInput[3]), parse_number(parsedInput[4]));

    free(parsedInput); 
    
    return SUCESS;
}