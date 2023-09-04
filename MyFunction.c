#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
//SORTING ALGORITHM
void BubbleSort(int size, int* array)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i]; array[i] = array[j]; array[j] = temp;
            }
        }
    }
}
void InsertionSort(int size, int* array)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i], limit = i - 1;
        while (limit >= 0 && array[limit] > key)
        {
            array[limit + 1] = array[limit];
            limit--;
        }
        array[limit + 1] = key;
    }
}
void SelectionSort(int size, int* array)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = -1;
        for (int j = i; j < size; j++)
        {
            if (j == i) minIndex = j;
            else if (array[j] < array[minIndex]) minIndex = j;
        }
        if (minIndex != i)
        {
            int temp = array[i]; array[i] = array[minIndex]; array[minIndex] = temp;
        }
    }
}
void CountingSort(int* array, int size)
{
    int max = array[0], min = array[0];
    for (int i = 1; i < size; i++)
    {
        max = array[i] > max ? array[i] : max;
        min = array[i] < min ? array[i] : min;
    }
    int range = max - min + 1, count[range], output[size];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < size; i++) count[array[i] - min]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i] - min] - 1] = array[i];
        count[array[i] - min]--;
    }
    for (int i = 0; i < size; i++) array[i] = output[i];
}
void MergeSort(int* array, int low, int high)
{
    if (low < high)
    {
        int middle = low + (high - low) / 2;
        MergeSort(array, low, middle); MergeSort(array, middle + 1, high);
        int leftSize = middle - low + 1, rightSize = high - middle, leftArray[leftSize], rightArray[rightSize];
        for (int i = 0; i < leftSize; i++) leftArray[i] = array[low + i];
        for (int j = 0; j < rightSize; j++) rightArray[j] = array[middle + 1 + j];
        int i = 0, j = 0, k = low;
        while (i < leftSize && j < rightSize)
        {
            if (leftArray[i] <= rightArray[j]) { array[k] = leftArray[i]; i++; }
            else { array[k] = rightArray[j]; j++; } k++;
        }
        while (i < leftSize) { array[k] = leftArray[i]; i++; k++; }
        while (j < rightSize) { array[k] = rightArray[j]; j++; k++; }
    }
}
void QuickSort(int* array, int low, int high)
{
    if (low < high)
    {
        int pivot = array[high], i = low - 1;
        for (int j = low; j <= high - 1; j++)
        {
            if (array[j] < pivot)
            {
                i++; int temp = array[i]; array[i] = array[j]; array[j] = temp;
            }
        }
        int temp = array[i + 1]; array[i + 1] = array[high]; array[high] = temp;
        int partition = i + 1;
        QuickSort(array, low, partition - 1); QuickSort(array, partition + 1, high);
    }
}
void RadixSort(int* array, int size)
{
    int max = array[0], min = array[0];
    for (int i = 1; i < size; i++)
    {
        max = array[i] > max ? array[i] : max;
        min = array[i] < min ? array[i] : min;
    }
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        int range = max - min + 1, output[size], count[range];
        memset(count, 0, sizeof(count));
        for (int i = 0; i < size; i++) count[((array[i] - min) / exp) % 10]++;
        for (int i = 1; i < range; i++) count[i] += count[i - 1];
        for (int i = size - 1; i >= 0; i--)
        {
            output[count[((array[i] - min) / exp) % 10] - 1] = array[i];
            count[((array[i] - min) / exp) % 10]--;
        }
        for (int i = 0; i < size; i++) array[i] = output[i];
    }
}
//SEARCHING ALGORITHM
void LinearSearch(int size, int* array, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target) { printf("%d found at index %d\n", target, i + 1); return; }
    }
    printf("%s", "Target not found!\n");
}
void BinaryInterpolationSearch(int size, int* array, int target)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2; //Standard Binary
        // int middle = left + ((right - left) * (target - array[left]) / (array[right] - array[left])); //Interpolation Binary
        if (array[middle] == target) { printf("%d found at index %d\n", target, middle); return; }
        else if (array[middle] < target) left = middle + 1;
        else right = middle - 1;
    }
    printf("%s", "Target not found\n");
}
void ExponentialSearch(int size, int* array, int target)
{
    int position = 1;
    while (position < size - 1 && array[position] < target) position *= 2;
    int left = position / 2, right = (size - 1) > position ? position : (size  - 1);
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (array[middle] == target) { printf("%d found at index %d\n", target, middle); return; }
        else if (array[middle] < target) left = middle + 1;
        else right = middle - 1;
    }
    printf("%s", "Target not found\n");
}
//COIN CHANGE
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
//KNAPSACK LIKE PROBLEM
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
//LONGEST INCREASING SUBSEQUENCES
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
//LONGEST COMMON SUBSEQUENCES
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
//TRAVELING SLAESMAN PROBLEM
int traveling_salesman_problem(int N, int W[101][101], int idx, int visited)
{
    if (visited == (1 << N) - 1) return W[idx][0];
    int ret = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        if (visited & (1 << i)) continue;
        ret = min(ret, traveling_salesman_problem(N, W, i, visited | (1 << i)) + W[idx][i]);
    }
    return ret;
}
int traveling_salesman_problem_memo(int N, int W[101][101], int idx, int visited)
{
    if (visited == (1 << N) - 1) return W[idx][0];
    int &ret = DP_2D[idx][visited];
    if (ret != -1) return ret;
    ret = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        if (visited & (1 << i)) continue;
        ret = min(ret, traveling_salesman_problem_memo(N, W, i, visited | (1 << i)) + W[idx][i]);
    }
    return ret;
}
int traveling_salesman_problem_tabulation(int N, int W[101][101])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            if (j == 0) DP_2D[i][j] = W[i][0];
            else DP_2D[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j)) continue;
            for (int k = 0; k < N; k++)
            {
                if (i & (1 << k)) continue;
                DP_2D[k][i | (1 << k)] = min(DP_2D[k][i | (1 << k)], DP_2D[j][i] + W[j][k]);
            }
        }
    }
    return DP_2D[0][(1 << N) - 1];
}
//s