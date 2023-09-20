#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int DP[1000000] = {};
int DP_2D[1000][1000] = {};

// Eight Queen Problem



void initialize()
{
    memset(DP, -1, sizeof(DP));
    memset(DP_2D, -1, sizeof(DP_2D));
}
int main(int argc, char** argv)
{
    initialize();
    printf("%d\n", eight_queen_problem(8, 0, 8));
    return 0;
}