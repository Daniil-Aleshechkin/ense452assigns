#include <stdlib.h>
#include "num_utils.h"
#include "parse_number_string.h"
#include <stdbool.h>
#include <stdio.h>

#define ARG_COUNT 5
int parseChar(char);
int computeStringLen(char*);
int getNumberOrder(char*);

int parseChar(char character) {
    switch (character)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        return 0;
    }
}

int computeStringLen(char* inputString) {
    int len = 0;
    int i = 0;

    while(inputString[i] != 0x00) {
        len++;
    }

    return len;
}

// Validates a string based on the following condictions
// 1. 0 or 1 - sign at the start of the number
// 2. 0 or 1 . BEFORE an e exponent if it exists and must not be first character
// 3. 0 or 1 e AFTER a . if it exists and must not be first character
// 4. all other characters must be from 0-9
bool validateNumberString(char* number) {
    bool isNegative = false;
    bool isDecimal = false;
    bool isScientific = false;

    int exponentLocation = -1;
    int decimalLocation = -1;

    int i = 0;
    while(number[i] != 0x00) {
        if (number[i] == '-') {
            if ( isNegative && i != exponentLocation - 1) {
                return false;
            }

            isNegative = true;
            
            i++;
            continue;
        }

        if (number[i] == '.') {
            if (isDecimal || isScientific) {
                return false;
            }

            decimalLocation = i;
            isDecimal = true;
            
            i++;
            continue;
        }

        if (number[i] == 'e') {
            if (isScientific || i == 0) {
                return false;
            }

            exponentLocation = i;
            isScientific = true;
            
            i++;
            continue;
        }

        if (number[i] != '0' && parseChar(number[i]) == 0) {

            return false;
        }

        i++;
    }

    if (isScientific && isDecimal && decimalLocation > exponentLocation) {
        printf("NON");
        return false;
    }

    return true;
}

double parse_number(char* number) {
    int order = getNumberOrder(number);

    double orderMultiple = powTen(order);

    double value = 0;

    bool isNegative = false;

    int i = 0;
    while (number[i] != 0x00 && number[i] != 'e') {
        switch (number[i])
        {
        case '-':
            isNegative = true;
        case '.':
            break;
        default:
            value += parseChar(number[i]) * orderMultiple;
            orderMultiple = orderMultiple / 10;
            break;
        }

        i++;
    }

    if (isNegative) {    
        return -value;
    } else {
        return value;
    }
}

int getNumberOrder(char* number) {
    int numberOrder = 0;
    int i = 0;

    int decimalPosition = -1;

    bool isScientificNotation = false;

    bool isNegative = false;

    while (number[i] != 0x00) {
        if (number[i] == '.') {
            decimalPosition = i;
        }

        if (number[i] == 'e') {
            isScientificNotation = true;
            break;
        }

        if (number[i] == '-') {
            isNegative = true;
        }

        i++;
    }
    
    if (decimalPosition != -1) {
        numberOrder = decimalPosition - 1;
    } else {
        numberOrder = i - 1;
    }

    if (isNegative) {
        numberOrder--;
    }

    if (isScientificNotation) {
        numberOrder += (int)parse_number(number + i + 1);
    }

    return numberOrder;
}