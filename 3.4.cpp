//3.4

#include <iostream>
#include <vector>
 
int findIndexEqualToValue(const std::vector<int>& arr) {
   int left = 0;
   int right = arr.size() - 1;
 
   while (left <= right) {
       int mid = left + (right - left) / 2;
 
       if (arr[mid] == mid) {
           // A[mid] = mid, found the index
           return mid;
       } else if (arr[mid] > mid) {
           // A[mid] > mid, search on the left side
           right = mid - 1;
       } else {
           // A[mid] < mid, search on the right side
           left = mid + 1;
       }
   }
 
   // No index found
   return -1;
}
 
int main() {
   std::vector<int> arr1 = {-10, -5, 1, 3, 7, 9, 12, 17}; // Example 1
   std::vector<int> arr2 = {0, 2, 5, 8, 10, 14, 18};      // Example 2
 
   int result1 = findIndexEqualToValue(arr1);
   int result2 = findIndexEqualToValue(arr2);
 
   std::cout << "Example 1: Index i such that A[i] = i is " << result1 << std::endl;
   std::cout << "Example 2: Index i such that A[i] = i is " << result2 << std::endl;
 
   return 0;
}