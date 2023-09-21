# Complex Calculator Documentation

## Introduction

Welcome to the Complex Calculator documentation for ENSE 472. This calculator is designed to perform operations on complex numbers. This documentation will guide you through its usage, input format, supported commands, and error codes

## Usage Guide

To use the Complex Calculator, input is read from the standard input (stdin). You should provide five arguments in the following format:

```
C A B C D
```

Where:

- `C` is the command, which is case-insensitive and can be one of the following:

  - `M` for multiplication
  - `A` for addition
  - `S` for subtraction
  - `D` for division
  - `Q` to quit the calculator

- `A` is the real part of the first complex number.
- `B` is the imaginary part of the first complex number.
- `C` is the real part of the second complex number.
- `D` is the imaginary part of the second complex number.

The result of the operation will be sent to standard output (stdout) in the following format:

```
X + j Y
```

## Argument Format

Each argument must be a number and can include exactly one negative sign at the beginning and one decimal point. Additionally, scientific notation is supported by entering an 'e' followed by an integer exponent, for example:

```
1.2e10
```

The exponent must be an integer. Any other non-numeric characters will be considered invalid input.

## Error Codes

The Complex Calculator may produce the following error codes to help you diagnose issues:

- **error code 1: illegal Command**

  - This error occurs when the first argument you entered is not a supported command. Commands should be one of (M, A, S, D, Q).

- **error code 2: missing arguments**

  - This error occurs when you have entered too few arguments. All commands, except 'Q', require at least five arguments.

- **error code 3: extra arguments**

  - This error occurs when you have entered too many arguments (more than six).

- **error code 4: divide by zero**

  - This error is specific to the division operation. It happens when you attempt to divide by zero, i.e., when both `C` and `D` are equal to zero.

- **error code 5: invalid input**

  - This error indicates that one or more of the inputs provided do not adhere to the validation rules.

- **error code 6: unknown error**
  - This error is a catch-all for all other exceptional internal errors. It suggests that something went seriously wrong within the calculator.

## Build Instructions

To build the app simply run make on the make file. I couldn't figure out how to make the clean work properly in windows, so you'll just have to do it manually with.

```
rm *.o
rm *.exe
```

The make file will output the executable as complexCalculator.exe
