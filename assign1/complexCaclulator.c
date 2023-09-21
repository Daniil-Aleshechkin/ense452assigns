#include "calculator.h"
#include "error_handling.h"
#include <stdlib.h>
#include <stdbool.h>


int main() {
    Calculator* calcultor = createCalculator();

    while (true) {
        enum Result result = readInput(calcultor);
        
        if (result == SUCESS) {
            calculate(calcultor);
            printOutput(calcultor);
        } else {
            printResult(result);
        }
    }

    return 0;
}