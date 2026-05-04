#include "input.h"

double input_number(char number_place[])
{
    double result;
    printf("Enter your %s number: ", number_place);
    if (scanf("%lf", &result) != 1) 
    {
        printf("Invalid input\n");
        return 1;
    }
    return result;
}

double input_op()
{
    char result;
    printf("Enter operator: ");
    if (scanf(" %c", &result) != 1) 
    {
        printf("Invalid input\n");
        return 1;
    }
    return result;
}