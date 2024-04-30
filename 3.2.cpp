//3.2

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int hasTripletWithSum(int arr[], int n, int K) {
    qsort(arr, n, sizeof(int), compare); // Step 1: Sort the array in O(nlogn) time

    // Step 2: Iterate through each element of the array
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        // Step 4: In the inner loop, while left is less than right
        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right]; // Calculate the sum

            if (currentSum == K) { // If sum is equal to K, return true
                return 1;
            } else if (currentSum < K) { // If sum is less than K, increment left
                left++;
            } else { // If sum is greater than K, decrement right
                right--;
            }
        }
    }

    // Step 5: If no such triplet is found, return false
    return 0;
}

// Example usage
int main() {
    int arr[] = {1, 4, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 21;
    
    if (hasTripletWithSum(arr, n, K)) {
        printf("There exist three elements with sum equal to %d\n", K);
    } else {
        printf("No such triplet exists with sum equal to %d\n", K);
    }

    return 0;
}
