#include <stdlib.h>
#include "calc.h"
#include "input.h"
#include "logic.h"

// simple calculator
int main(int argc, char *argv[])
{
    double first, second;
    double result = -1;
    char op;

    /*
    if (argc == 3)
    {
        first = atof(argv[1]);
        op = atof(argv[2]);
        second = atof(argv[3]);
    }
    */
    
    printf("This is a simple calculator written in c\n");
    
    first = input_number("first");

    op = input_op();

    second = input_number("second");
    
    result = calculate(first, op, second);

    printf("Result: %.4f\n", result);

    return 0;
}