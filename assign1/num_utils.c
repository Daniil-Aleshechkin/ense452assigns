#include <stdlib.h>
#include "num_utils.h"

#define MAX_PRECISION 10

double powTenPositive(int);
double powTenNegative(int);

double powTen(int exp) {
    if (exp == 0) {
        return 1;
    } else if (exp < 0) {
        return powTenNegative(exp);
    } else {
        return powTenPositive(exp);
    }
}

double powTenPositive(int exp){
    double value = 1;

    for (int i = 0; i < exp; i++) {
        value = value * 10;
    }

    return value;
}

double powTenNegative(int exp) {
    double value = 1;

    for (int i = exp; i < 0; i++) {
        value = value / 10;
    }

    return value;
}

int countPrecision(double in) {
    int decimalPlaces = 0;
    double tempNum = in;
    while (decimalPlaces < MAX_PRECISION && (tempNum - (int)tempNum) > 0) {
        tempNum *= 10;
        decimalPlaces++;
    }
    return decimalPlaces;
}

double absValue(double in) {
    if (in < 0) {
        return -in;
    } else{
        return in;
    }
}