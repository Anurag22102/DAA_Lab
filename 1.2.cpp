//1.2
#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    for (int i = 0, j = 0, k = l; k <= r; ++k) {
        if (i == n1 || (j < n2 && R[j] < L[i]))
            arr[k] = R[j++]; 
        else
            arr[k] = L[i++]; 
    }
}


void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, arr_size - 1); 
    cout << "Time complexity of Merge Sort: O(n log n)" << endl;
    cout << "Sorted array is: ";
    printArray(arr, arr_size); 
    return 0;
}
