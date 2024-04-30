//1.4
#include <stdio.h>

// Function to check if there is an index i for which A[i] = i
int findIndexEqualToValue(int arr[], int start, int end) {
    if (start <= end) {
        int mid = start + (end - start) / 2;

        // Check if the current element is equal to its index
        if (arr[mid] == mid)
            return mid;

        // If the current element is greater than its index, search in the left subarray
        if (arr[mid] > mid)
            return findIndexEqualToValue(arr, start, mid - 1);
        // If the current element is less than its index, search in the right subarray
        else
            return findIndexEqualToValue(arr, mid + 1, end);
    }

    // If no such index is found
    return -1;
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get sorted array elements from the user
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find an index i for which A[i] = i
    int result = findIndexEqualToValue(arr, 0, n - 1);

    // Display the result
    if (result != -1)
        printf("Index %d satisfies A[%d] = %d.\n", result, result, result);
    else
        printf("No such index found.\n");

    return 0;
}