#include "io_utils.h"
#include "error_handling.h"
#include <stdlib.h>
#include <stdio.h>

#define ARG_COUNT 5
char* parseArg(char*, int*, enum Result*);
char** parseArgs(char*, enum Result*);

char** read_args(enum Result* result) {
    char inputStringBuffer[100];
    if (fgets(inputStringBuffer, sizeof(inputStringBuffer), stdin) == NULL) {
        *result = UNKNOWN; // Error reading input
    }

    if (inputStringBuffer[0] == 'q' || inputStringBuffer[0] == 'Q') {
        *result = EXIT_REQUEST;
        return NULL;
    } else {    
        return parseArgs(inputStringBuffer, result);    
    }
}

char** parseArgs(char* bufferPtr, enum Result* result) {
    char** outputArgStrings = (char**)malloc(sizeof(char*)*5);

    int* inStrIndex = (int*)malloc(sizeof(int));
    *inStrIndex = 0;

    enum Result testResult = SUCESS;
    for (int i = 0; i < ARG_COUNT ; i++) {
        outputArgStrings[i] = parseArg(bufferPtr, inStrIndex, &testResult); 
    
        if (testResult != SUCESS) {
            *result = TOO_FEW_ARGS;
            free(inStrIndex);
            return outputArgStrings;
        }
    }
    
    parseArg(bufferPtr, inStrIndex, &testResult);
    if (testResult != TOO_FEW_ARGS) {
        (*result) = TOO_MANY_ARGS;
        free(inStrIndex);
        return outputArgStrings;
    }

    return outputArgStrings;
}

char* parseArg(char* instr, int* inStrIndex, enum Result* result) {
    // Remove starting in spaces
    while (instr[*inStrIndex] == ' ') {
        *inStrIndex = *inStrIndex + 1;
    }

    // Find out how much mem we need to allocate
    int argLength = 0;
    while (instr[argLength + *inStrIndex] != ' ' && instr[argLength + *inStrIndex] != 0x00 && instr[argLength + *inStrIndex] != '\n') {
        argLength++;
    }

    if (argLength == 0) {
        *result = TOO_FEW_ARGS;
        return NULL;
    }

    char* outstr = (char*)malloc(sizeof(char) * (size_t)(argLength + 1));
    
    // Copy the string
    for (int i = 0; i < argLength; i++) {
        outstr[i] = instr[*inStrIndex];
        *inStrIndex = *inStrIndex + 1;
    }

    outstr[argLength] = 0x00;

    *result = SUCESS;
    return outstr;
}
