#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);
void printer(int *arr, int size);

int main()
{
    // s
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void printer(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d%c", arr[i], i == size - 1 ? '\n' : ' ');
    return;
}