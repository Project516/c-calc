#include "logic.h"
#include "calc.h"

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
            int whole_first = first;
            int whole_second = second;
            result = whole_first % whole_second;
            break;
        // fall back
        default:
            printf("Unknown operator\n");
            break;
    }
    return result;
}