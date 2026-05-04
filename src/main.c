#include "calc.h"

// simple calculator
int main(void)
{
    double first, second;
    double result = -1;
    char op;
    
    printf("This is a simple calculator written in c\n");
    
    printf("Enter your first number: ");
    if (scanf("%lf", &first) != 1) 
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter operator: ");
    if (scanf(" %c", &op) != 1) 
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter your second number: ");
    if (scanf("%lf", &second) != 1) 
    {
        printf("Invalid input\n");
        return 1;
    }

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