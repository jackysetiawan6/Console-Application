#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int DP[1000000] = {};
int DP_2D[1000][1000] = {};

int is_palindrome(char string[], int LEFT, int RIGHT)
{
    while (LEFT < RIGHT)
    {
        if (string[LEFT++] != string[RIGHT--])
        {
            return 0;
        }
    }
    return 1;
}

int is_unique(char string[], int start, int end)
{
    int index = 0, first = string[start] - 97;
    for (int i = start; i <= end; i++)
    {
        index = index + ((string[i] - 96) << 1);
    }
    if (DP_2D[first][index] == 1)
    {
        return 0;
    }
    printf("%02d --- %02d\n", first, index);
    DP_2D[first][index] = 1;
    return 1;
}

int print_substring(char STRING[])
{
    int COUNT = 0;
    int LENGTH = (int)strlen(STRING);
    for (int i = 1; i <= LENGTH; i++)
    {
        for (int j = 0; j < LENGTH - i + 1; j++)
        {
            if (is_palindrome(STRING, j, j + i - 1))
            {
                if (is_unique(STRING, j, j + i - 1)) COUNT++;
            }
        }
    }
    return COUNT;
}

int main(int argc, char *argv[])
{
    char kata[1000] = "";
    scanf("%[^\n]", kata);
    printf("%d\n", print_substring(kata));
    return 0;
}