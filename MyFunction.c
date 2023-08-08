#include <stdio.h>
//SORTING
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
//SEARCHING
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
//MISCELLANEOUS
void Palindrome(int* array, int size)
{
    int left = 0, right = size - 1;
    while (left < right)
    {
        if (array[left] != array[right]) { printf("%s", "It is not a palindrom\n"); return; }
        left++; right--;
    }
    printf("%s", "It is a palindrom\n");
}
void SubArraySum(int* array, int size, int target)
{
    for (int i = 1; i < size; i++) array[i] = array[i - 1] + array[i];
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] - array[i] == target) { printf("%d found between index %d and %d\n", target, i + 1, j); return; }
        }
    }
    printf("%s", "Target not found\n");
}
int LongestCommonSubsequence(char* string1, char* string2, int size1, int size2)
{
    int table[size1 + 1][size2 + 1];
    for (int i = 0; i <= size1; i++)
    {
        for (int j = 0; j <= size2; j++)
        {
            if (i == 0 || j == 0) table[i][j] = 0;
            else if (string1[i - 1] == string2[j - 1]) table[i][j] = table[i - 1][j - 1] + 1;
            else table[i][j] = table[i - 1][j] > table[i][j - 1] ? table[i - 1][j] : table[i][j - 1];
        }
    }
    return table[size1][size2];
}
void FloodFill(int** array, int size, int row, int column, int target, int replacement)
{
    if (row < 0 || column < 0 || row >= size || column >= size) return;
    if (array[row][column] != target) return;
    array[row][column] = replacement;
    FloodFill(array, size, row + 1, column, target, replacement); FloodFill(array, size, row - 1, column, target, replacement);
    FloodFill(array, size, row, column + 1, target, replacement); FloodFill(array, size, row, column - 1, target, replacement);
}
void LeeAlgorithm(int** array, int size, int row, int column, int target, int replacement)
{
    int queue[size * size][2], front = 0, rear = 0;
    queue[rear][0] = row; queue[rear][1] = column; rear++;
    while (front < rear)
    {
        int currentRow = queue[front][0], currentColumn = queue[front][1]; front++;
        if (currentRow < 0 || currentColumn < 0 || currentRow >= size || currentColumn >= size) continue;
        if (array[currentRow][currentColumn] != target) continue;
        array[currentRow][currentColumn] = replacement;
        queue[rear][0] = currentRow + 1; queue[rear][1] = currentColumn; rear++;
        queue[rear][0] = currentRow - 1; queue[rear][1] = currentColumn; rear++;
        queue[rear][0] = currentRow; queue[rear][1] = currentColumn + 1; rear++;
        queue[rear][0] = currentRow; queue[rear][1] = currentColumn - 1; rear++;
    }
}
int SubsetSum(int* array, int size, int target)
{
    if (target == 0) return 1;
    if (size == 0) return 0;
    if (array[size - 1] > target) return SubsetSum(array, size - 1, target);
    return SubsetSum(array, size - 1, target) || SubsetSum(array, size - 1, target - array[size - 1]);
}
int LowerBound(int *array, int N, int X)
{
	int low = 0, high = N;
	while (low < high)
    {
		int mid = (low + high) / 2;
    	if (X <= array[mid]) high = mid;
    	else low = mid + 1;
	}
	if (low < N && array[low] < X) low++;
    return low;
}
int UpperBound(int *array, int N, int X)
{
	int low = 0, high = N;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (X >= array[mid]) low = mid + 1;
        else high = mid;
    }
    if (low < N && array[low] <= X) low++;
    return low;
}
//HASH FUNCTIONS
unsigned long hashDJB2(char *str)
{
    unsigned long hash = 5381; int c;
    while (c = *str++) hash = ((hash << 5) + hash) + c;
    return hash;
}
unsigned long hashSDBM(char *str)
{
    unsigned long hash = 0; int c;
    while (c = *str++) hash = c + (hash << 6) + (hash << 16) - hash;
    return hash;
}
unsigned long hashLOSELOSE(char *str)
{
    unsigned long hash = 0; int c;
    while (c = *str++) hash += c;
    return hash;
}
unsigned long hashRS(char *str)
{
    unsigned long b = 378551; unsigned long a = 63689; unsigned long hash = 0; int c;
    while (c = *str++) { hash = hash * a + c; a = a * b; }
    return hash;
}
unsigned long hashJS(char *str)
{
    unsigned long hash = 1315423911; int c;
    while (c = *str++) hash ^= ((hash << 5) + c + (hash >> 2));
    return hash;
}
unsigned long hashELF(char *str)
{
    unsigned long hash = 0; unsigned long x = 0; int c;
    while (c = *str++) { hash = (hash << 4) + c; if ((x = hash & 0xF0000000L) != 0) { hash ^= (x >> 24); hash &= ~x; } }
    return hash;
}
unsigned long hashBKDR(char *str)
{
    unsigned long hash = 0; int c;
    while (c = *str++) hash = (hash * 131) + c;
    return hash;
}