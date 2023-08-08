#include <stdio.h>
#include <stdlib.h>

void problem01()
{
    system("cls");
    while (1)
    {
        int size = 0;
        printf("    Enter the size of right triangle: ");
        scanf("%d", &size);
        getchar();
        if (size == 0) break;
        else if (size < 0) printf("Invalid size!\n");
        else
        {
            for (int i = 1; i <= size; i++)
            {
                printf("%02d: ", i);
                for (int j = 1; j <= size; j++) printf(j <= size - i ? " " : "*");
                printf("\n");
            }
        }
    }
    return;
}

void problem02()
{
    system("cls");
    int operand1 = 0, operand2 = 0;
    char operator = ' ';
    while (operator!= '0')
    {
        printf("    Enter the expression: ");
        scanf("%d %c %d", &operand1, &operator, & operand2);
        getchar();
        if (operator== '+' || operator== '-' || operator== '*' || operator== '/')
        {
            int result = 0;
            switch (operator)
            {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            printf("    Result: %d %c %d = %d\n", operand1, operator, operand2, result);
        }
        else if (operator!= '0') printf("Invalid operator!\n");
    }
    return;
}

int main()
{
    problem02();
    return 0;
}