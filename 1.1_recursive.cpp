//1.1
#include <iostream>
#include <vector>
 
int binarySearchRecursive(const std::vector<int>& arr, int target, int left, int right) {
   if (left <= right) {
       int mid = left + (right - left) / 2;
 
       if (arr[mid] == target) {
           return mid;
       }
       if (arr[mid] > target) {
           return binarySearchRecursive(arr, target, left, mid - 1);
       }
 
       return binarySearchRecursive(arr, target, mid + 1, right);
   }
 
   return -1;
}
 
int main() {
   std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int target = 5;
 
   int result = binarySearchRecursive(arr, target, 0, arr.size() - 1);
   std::cout << "Time complexity of Binary Search (Recursive): O(log n)" << std::endl;
   if (result != -1) {
       std::cout << "Element found at index: " << result << std::endl;
   } else {
       std::cout << "Element not found in the array." << std::endl;
   }
 
   return 0;
}