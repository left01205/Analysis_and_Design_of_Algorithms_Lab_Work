#include <stdio.h>
#include <limits.h>

#define MAX 1000

int segmentTree[4 * MAX];
int arr[MAX];

// Function to build the segment tree
void buildTree(int node, int start, int end) {
    if (start == end) {
        segmentTree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildTree(2 * node + 1, start, mid);
        buildTree(2 * node + 2, mid + 1, end);
        segmentTree[node] = (segmentTree[2 * node + 1] < segmentTree[2 * node + 2]) ? segmentTree[2 * node + 1] : segmentTree[2 * node + 2];
    }
}

// Function to query the minimum value in a given range
int query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
        return INT_MAX;
    }
    if (L <= start && end <= R) {
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    int leftMin = query(2 * node + 1, start, mid, L, R);
    int rightMin = query(2 * node + 2, mid + 1, end, L, R);
    return (leftMin < rightMin) ? leftMin : rightMin;
}

int main() {
    int n, q, L, R;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    buildTree(0, 0, n - 1);

    printf("Enter the number of queries: ");
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        printf("Enter the range (L R): ");
        scanf("%d %d", &L, &R);
        printf("Minimum value in range [%d, %d] is %d\n", L, R, query(0, 0, n - 1, L, R));
    }

    return 0;
}