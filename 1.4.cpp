#include <iostream>
#include <cmath>


bool isIndexEqualToValue(int arr[], int size) {
    int low = 0;
    int high = size - 1;


    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == mid)
            return true;
        else if (arr[mid] < mid)
            low = mid + 1;
        else
            high = mid - 1;
    }


    return false;
}


int main() {
    int arr[] = {-10, -5, 0, 3, 7, 9, 12, 15};
    int size = sizeof(arr) / sizeof(arr[0]);


    if (isIndexEqualToValue(arr, size))
        std::cout << "Yes, there exists an index i for which A[i] = i.\n";
    else
        std::cout << "No, there doesn't exist an index i for which A[i] = i.\n";


    return 0;
}
