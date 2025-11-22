#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int binarySearch(vector<int>& arr, int start, int end, int x) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x) return mid;
            if (arr[mid] < x)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    int findPivot(vector<int>& arr, int start, int end) {
        while (start <= end) {
            // array is already soted in ascending.
            if (arr[start] <= arr[end]) return start;

            // The right half is not sorted.
            int mid = (start + end) / 2;
            if (arr[mid] > arr[end]) start = mid + 1;

            // The right half is sorted.
            else
                end = mid;
        }

        return start;
    }

    int search(vector<int>& arr, int key) {
        int n = arr.size();
        // pivot break the array in two sorted halves.
        int pivot = findPivot(arr, 0, n - 1);

        if (arr[pivot] == key) return pivot;

        if (pivot == 0) return binarySearch(arr, 0, n - 1, key);

        // If key < arr[0] → it must be in the right half
        // as it contain the max element
        // agar usse bhi bada h toh -1
        if (arr[0] <= key) return binarySearch(arr, 0, pivot - 1, key);

        return binarySearch(arr, pivot + 1, n - 1, key);
    }

    int searchSingleBS(vector<int>& arr, int key) {
        int start = 0, end = arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == key) return mid;

            // If Left half is sorted
            if (arr[mid] >= arr[start]) {
                // If the key lies witenin this sorted half,
                if (key >= arr[start] && key < arr[mid]) end = mid - 1;
                else start = mid + 1;
            }

            // If Right half is sorted
            else {
                // If the key lies witenin this sorted half,
                if (key > arr[mid] && key <= arr[end]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    Solution sol;
    cout << sol.search(arr, key);
    return 0;
}