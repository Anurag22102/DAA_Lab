#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int findMaxOccurringElement(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare); 

    int maxElement = arr[0]; 
    int maxCount = 1; 
    int currentElement = arr[0];
    int currentCount = 1; 

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxElement = currentElement;
                maxCount = currentCount;
            }
            currentElement = arr[i];
            currentCount = 1;
        }
    }

    if (currentCount > maxCount) {
        maxElement = currentElement;
        maxCount = currentCount;
    }

    return maxElement;
}

// Example usage
int main() {
    int arr[] = {3, 2, 5, 4, 2, 5, 6, 2, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxOccurringElement = findMaxOccurringElement(arr, n);
    printf("Element with maximum occurrences: %d\n", maxOccurringElement);

    return 0;
}
