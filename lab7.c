#include <stdio.h>
#include <stdlib.h>

void bubble(int arr[], int n, int swaps[]) {
    int size = arr[0];
    for (int i = 1;i < n;i++) {
        if (arr[i] > size) {
            size = arr[i];
        }
    }

    for (int i = 0;i < n - 1;i++) {
        for (int j = 0;j < n - i - 1;j++) {
            if (arr[j] > arr[j + 1]) {
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selection(int arr[], int n, int swaps[]) 
{
    int size = arr[0];
    for (int i = 1;i < n;i++) 
    {
        if (arr[i] > size) {
            size = arr[i];
        }
    }

    for (int i = 0;i < n - 1;i++) 
    {
        int minIndex = i;
        for (int j = i + 1;j < n;j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swaps[arr[i]]++;
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}

void sort(int array[], int n, char* num, void (*sortFunc)(int[], int, int[])) {
    int size = array[0];
    for (int i = 1;i < n;i++) {
        if (array[i] > size) {
            size = array[i];
        }
    }

    int *swaps = (int *)calloc(size + 1, sizeof(int));
    sortFunc(array, n, swaps);

    printf("%s:\n", num);
    for (int i = 0;i < n;i++) {
        printf("%d: %d\n", array[i], swaps[array[i]]);
    }

    int total = 0;
    for (int i = 0;i <= size;i++) {
        total += swaps[i];
    }
    printf("%d\n\n", total / 2);

    free(swaps);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    sort(array1, n1, "array1 bubble sort", bubble);
    sort(array2, n2, "array2 bubble sort", bubble);
    sort(array1, n1, "array1 selection sort", selection);
    sort(array2, n2, "array2 selection sort", selection);

    return 0;
}
