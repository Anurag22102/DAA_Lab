//3.3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

bool has_sum(vector<int>& A, vector<int>& B, int K) {
    sort(B.begin(), B.end());

    for (int i = 0; i < A.size(); ++i) {
        int required = K - A[i];
        if (binary_search(B, required))
            return true;
    }

    return false;
}

int main() {
    vector<int> A = {1, 4, 7, 9, 11};
    vector<int> B = {3, 6, 8, 10, 12};
    int K = 13;

    if (has_sum(A, B, K))
        cout << "There exist a and b such that a + b = " << K << endl;
    else
        cout << "No such a and b found." << endl;

    return 0;
}
