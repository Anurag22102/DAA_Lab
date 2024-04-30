//1.3
#include <iostream>
#include <chrono>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {

    int arr[] = {12, 7, 11, 8, 5, 3, 2, 9, 6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    auto start_time = chrono::high_resolution_clock::now();
    quicksort(arr, 0, arr_size - 1);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Time complexity of Quick Sort: O(n log n) [Average Case], O(n^2) [Worst Case]" << endl;

    cout << "Sorted array: ";
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i] << " ";
    }

    //cout << "\nTime taken by Quicksort: " << duration.count() << " microseconds" << endl;

    return 0;
}
