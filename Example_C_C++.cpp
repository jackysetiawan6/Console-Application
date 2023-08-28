#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int DP[1000000] = {};
int DP_2D[1000][1000] = {};

int coin_change(int x)
{
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;
    return min(coin_change(x - 1), min(coin_change(x - 3), coin_change(x - 4))) + 1;
}
int coin_change_memo(int x)
{
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;
    if (DP[x] != -1) return DP[x];
    DP[x] = min(coin_change_memo(x - 1), min(coin_change_memo(x - 3), coin_change_memo(x - 4))) + 1;
    return DP[x];
}
int coin_change_tabulation(int x)
{
    DP[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        DP[i] = DP[i - 1] + 1;
        if (i >= 3) DP[i] = min(DP[i], DP[i - 3] + 1);
        if (i >= 4) DP[i] = min(DP[i], DP[i - 4] + 1);
    }
    return DP[x];
}

int knapsack_like(int N, int *W, int *V, int idx, int cap)
{
    if (cap < 0) return INT_MIN;
    if (idx > N) return 0;
    int ret = 0;
    ret = max(ret, knapsack_like(N, W, V, idx + 1, cap));
    ret = max(ret, knapsack_like(N, W, V, idx + 1, cap - W[idx]) + V[idx]);
    return ret;
}
int knapsack_like_memo(int N, int *W, int *V, int idx, int cap)
{
    if (cap < 0) return INT_MIN;
    if (idx > N) return 0;
    int &ret = DP_2D[idx][cap];
    if (ret != -1) return ret;
    ret = 0;
    ret = max(ret, knapsack_like_memo(N, W, V, idx + 1, cap));
    ret = max(ret, knapsack_like_memo(N, W, V, idx + 1, cap - W[idx]) + V[idx]);
    return ret;
}
int knapsack_like_tabulation(int N, int *W, int *V, int cap)
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            if (j == 0) DP_2D[i][j] = 0;
            else if (i == 0) DP_2D[i][j] = INT_MIN;
            else
            {
                DP_2D[i][j] = DP_2D[i - 1][j];
                if (j >= W[i - 1]) DP_2D[i][j] = max(DP_2D[i][j], DP_2D[i - 1][j - W[i - 1]] + V[i - 1]);
            }
        }
    }
    return DP_2D[N][cap];
}

int longest_increasing_subsequence(int N, int *A, int idx, int prev)
{
    if (idx == N) return 0;
    int ret = 0;
    if (A[idx] > prev) ret = max(ret, longest_increasing_subsequence(N, A, idx + 1, A[idx]) + 1);
    ret = max(ret, longest_increasing_subsequence(N, A, idx + 1, prev));
    return ret;
}
int longest_increasing_subsequence_memo(int N, int *A, int idx, int prev)
{
    if (idx == N) return 0;
    int &ret = DP_2D[idx][prev];
    if (ret != -1) return ret;
    ret = 0;
    if (A[idx] > prev) ret = max(ret, longest_increasing_subsequence_memo(N, A, idx + 1, A[idx]) + 1);
    ret = max(ret, longest_increasing_subsequence_memo(N, A, idx + 1, prev));
    return ret;
}
int longest_increasing_subsequence_tabulation(int N, int *A)
{
    for (int i = 0; i < N; i++)
    {
        DP_2D[i][0] = 0;
        for (int j = 1; j <= 1000; j++) DP_2D[i][j] = INT_MIN;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (j == 0) DP_2D[i][j] = 0;
            else if (i == 0) DP_2D[i][j] = INT_MIN;
            else
            {
                DP_2D[i][j] = DP_2D[i - 1][j];
                if (A[i] > j) DP_2D[i][j] = max(DP_2D[i][j], DP_2D[i - 1][A[i]] + 1);
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < N; i++) ret = max(ret, DP_2D[i][0]);
    return ret;
}

int longest_common_subsequence(char *string1, char *string2, int idx1, int idx2)
{
    if (idx1 == 0 || idx2 == 0) return 0;
    int ret = 0;
    if (string1[idx1 - 1] == string2[idx2 - 1]) ret = max(ret, longest_common_subsequence(string1, string2, idx1 - 1, idx2 - 1) + 1);
    ret = max(ret, longest_common_subsequence(string1, string2, idx1 - 1, idx2));
    ret = max(ret, longest_common_subsequence(string1, string2, idx1, idx2 - 1));
    return ret;
}
int longest_common_subsequence_memo(char *string1, char *string2, int idx1, int idx2)
{
    if (idx1 == 0 || idx2 == 0) return 0;
    int &ret = DP_2D[idx1][idx2];
    if (ret != -1) return ret;
    ret = 0;
    if (string1[idx1 - 1] == string2[idx2 - 1]) ret = max(ret, longest_common_subsequence_memo(string1, string2, idx1 - 1, idx2 - 1) + 1);
    ret = max(ret, longest_common_subsequence_memo(string1, string2, idx1 - 1, idx2));
    ret = max(ret, longest_common_subsequence_memo(string1, string2, idx1, idx2 - 1));
    return ret;
}
int longest_common_subsequence_tabulation(char *string1, char *string2, int idx1, int idx2)
{
    for (int i = 0; i <= idx1; i++)
    {
        for (int j = 0; j <= idx2; j++)
        {
            if (i == 0 || j == 0) DP_2D[i][j] = 0;
            else
            {
                DP_2D[i][j] = max(DP_2D[i - 1][j], DP_2D[i][j - 1]);
                if (string1[i - 1] == string2[j - 1]) DP_2D[i][j] = max(DP_2D[i][j], DP_2D[i - 1][j - 1] + 1);
            }
        }
    }
    return DP_2D[idx1][idx2];
}

void initialize()
{
    memset(DP, -1, sizeof(DP));
    memset(DP_2D, -1, sizeof(DP_2D));
}
int main(int argc, char** argv)
{
    initialize();
    char str1[1000] = "", str2[1000] = "";
    scanf("%s %s", str1, str2);
    printf("%d\n", longest_common_subsequence_memo(str1, str2, strlen(str1), strlen(str2)));
    return 0;
}