OBJECTS = io_utils.o calculator.o complexCaclulator.o parse_number_string.o complex.o num_utils.o error_handling.o
BINARY = complexCalculator.exe

CFLAGS = -Wextra -Wall -Wfloat-equal -Wconversion -Wparentheses -pedantic -Wunused-parameter -Wunused-variable -Wreturn-type -Wunused-function -Wredundant-decls -Wreturn-type -Wunused-value -Wswitch-default -Wuninitialized -Winit-self -Werror

all : $(BINARY)

$(BINARY) : $(OBJECTS)
	gcc $(CFLAGS) -o $@ $^

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $^

clean:
	rm *.o