#include <iostream>
#include <chrono>
#include <cstdlib> 
#include <ctime>   

using namespace std;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int size = 10; 
    int arr[size]= {1,5,2,6,8,3,4,10,7,9};

    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Sorted array:\n";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\n\nTime taken by Bubble Sort: " << duration.count() << " seconds\n";

    return 0;
}
