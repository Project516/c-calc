#include "calc.h"

// addition
double add (double a, double b)
{
    return a + b;
}

// subtraction
double subtract (double a, double b)
{
    return a - b;
}

// multiplication
double multiply (double a, double b)
{
    return a * b;
}

// division
double divide (double a, double b)
{
    if (b == 0) 
    {
        printf("Divide by 0 error");
        return 0;
    }
    return a / b;
}