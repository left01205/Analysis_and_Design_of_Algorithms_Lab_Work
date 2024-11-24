// Function to perform bucket sort on arr[]

#include <stdio.h>
#include <stdlib.h>
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    struct Bucket {
        int count;
        float* values;
    } buckets[n];

    for (int i = 0; i < n; i++) {
        buckets[i].count = 0;
        buckets[i].values = (float*)malloc(sizeof(float) * n);
    }

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].values[buckets[bucketIndex].count++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        if (buckets[i].count > 0) {
            for (int j = 1; j < buckets[i].count; j++) {
                float key = buckets[i].values[j];
                int k = j - 1;
                while (k >= 0 && buckets[i].values[k] > key) {
                    buckets[i].values[k + 1] = buckets[i].values[k];
                    k--;
                }
                buckets[i].values[k + 1] = key;
            }
        }
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].values[j];
        }
        free(buckets[i].values);
    }
}

// Driver program to test bucket sort
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    printf("Sorted array is \n");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
    return 0;
}