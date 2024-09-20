#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Key not found
}

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 12;

    // Perform linear search
    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1) {
        printf("Linear Search: Element found at index %d\n", linearResult);
    }
    else {
        printf("Linear Search: Element not found\n");
    }

    // Perform binary search
    int binaryResult = binarySearch(arr, 0, n - 1, key);
    if (binaryResult != -1) {
        printf("Binary Search: Element found at index %d\n", binaryResult);
    }
    else {
        printf("Binary Search: Element not found\n");
    }

    return 0;
}