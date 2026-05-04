#include <stdlib.h>
#include "calc.h"
#include "input.h"

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

    switch(op)
    {
        // addition
        case '+': 
            result = add(first, second);
            break;
        // subtraction
        case '-': 
            result = subtract(first, second);
            break;
        // multiplication
        case '*': 
            result = multiply(first, second);
            break;
        // division
        case '/': 
            result = divide(first, second);
            break;
        // remainder 
        case '%': 
            int whole_first = first;
            int whole_second = second;
            result = whole_first % whole_second;
            break;
        // fall back
        default:
            printf("Unknown operator\n");
            break;
    }

    printf("Result: %f\n", result);

    return 0;
}