/*

Hello, Visitor! This is my code that facilitates the execution of a quick sort algorithm on an array.
Feel free to use my codes to understand the core of C Data structure.

*/

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("\nEnter no of elements : ");
    scanf("%d", &n);
    int arr[n];

    printf("\nEnter elements to be sorted : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    printf("\nSorted elements =  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}