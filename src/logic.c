#include "logic.h"
#include "calc.h"
#include <math.h>

// calculate logic
double calculate(double first, char op, double second)
{
    double result = -1;
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
            result = fmod(first, second);
            break;
        // fall back
        default:
            printf("Unknown operator\n");
            break;
    }
    return result;
}