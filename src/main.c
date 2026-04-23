#include <stdio.h>

int main(void)
{
    float first, second, result;
    char op;
    
    printf("This is a simple calculator in c\n");
    
    printf("Enter your first number: ");
    scanf("%f", &first);

    printf("Enter operator: ");
    scanf(" %c", &op);

    printf("Enter your second number: ");
    scanf("%f", &second);

    switch(op)
    {
        case '+': 
            result = first + second;
            break;
        case '-': 
            result = first - second;
            break;
        case '*': 
            result = first * second;
            break;
        case '/': 
            if (second == 0) 
            {
                printf("Divide by zero error\n");
                break;
            }
            result = first / second;
            break;
        case '%': 
            int whole_first = first;
            int whole_second = second;
            result = whole_first % whole_second;
            break;
        default:
            printf("Unknown operator\n");
            break;
    }

    printf("Result: %f\n", result);

    return 0;
}