#include "calc.h"

double add (double a, double b)
{
    return a + b;
}

double subtract (double a, double b)
{
    return a - b;
}

double multiply (double a, double b)
{
    return a * b;
}

double divide (double a, double b)
{
    if (b == 0) 
    {
        printf("Divide by 0 error");
        return 0;
    }
    return a / b;
}