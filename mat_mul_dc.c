#include <stdio.h>
#include <stdlib.h>

// Function to multiply two numbers using divide and conquer
int multiply(int x, int y) {
    if (x < y) {
        return multiply(y, x);
    }
    if (y == 0) {
        return 0;
    }
    if (y == 1) {
        return x;
    }
    int half = multiply(x, y / 2);
    if (y % 2 == 0) {
        return half + half;
    } else {
        return half + half + x;
    }
}

// Function to count inversions in an array
int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left, inv_count = 0;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return inv_count;
}

int countInversions(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count += countInversions(arr, temp, left, mid);
        inv_count += countInversions(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

// Function to partition the array for quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Function to implement quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int x = 15, y = 25;
    printf("Multiplication of %d and %d is %d\n", x, y, multiply(x, y));

    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    printf("Number of inversions are %d\n", countInversions(arr, temp, 0, n - 1));

    int arr2[] = {10, 7, 8, 9, 1, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    quickSort(arr2, 0, n2 - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}