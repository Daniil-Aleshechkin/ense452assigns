#include "complex.h"
#include "error_handling.h"

#ifndef CALCULATOR
#define CALCULATOR

typedef struct {
    ComplexNum in1;
    ComplexNum in2;
    ComplexNum out;
    enum Result calculationResult;
    char mode;
} Calculator;

void printOutput(Calculator* calculator);
Calculator* createCalculator();
void calculate(Calculator* calculator);
enum Result readInput(Calculator* calculator);

#endif