#include <stdio.h>

// simple calculator
int main(void)
{
    double first, second;
    double result = -1;
    char op;
    
    printf("This is a simple calculator written in c\n");
    
    printf("Enter your first number: ");
    scanf("%lf", &first);

    printf("Enter operator: ");
    scanf(" %c", &op);

    printf("Enter your second number: ");
    scanf("%lf", &second);

    switch(op)
    {
        // addition
        case '+': 
            result = first + second;
            break;
        // subtraction
        case '-': 
            result = first - second;
            break;
        // multiplication
        case '*': 
            result = first * second;
            break;
        // division
        case '/': 
            if (second == 0) 
            // we dont want to divide by zero
            {
                printf("Divide by zero error\n");
                break;
            }
            result = first / second;
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