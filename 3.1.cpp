//3.1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool has_sum(vector<int>& arr, int K) {
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int current_sum = arr[left] + arr[right];
        if (current_sum == K)
            return true;
        else if (current_sum < K)
            left++;
        else
            right--;
    }

    return false;
}

int main() {
    vector<int> arr = {3, 7, 2, 9, 5, 8};
    int K = 10;

    if (has_sum(arr, K))
        cout << "There exist two elements whose sum is " << K << "." << endl;
    else
        cout << "No such two elements found." << endl;

    return 0;
}
