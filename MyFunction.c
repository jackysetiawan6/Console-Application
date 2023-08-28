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
//s