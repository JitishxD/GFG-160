#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int countAndMerge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;

        vector<int> left(n1), right(n2);
        for (int i = 0; i < n1; i++) left[i] = arr[i + l];
        for (int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];

        // Initialize inversion count(invCount) and merge two halves
        int invCount = 0;
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j])
                arr[k] = left[i++];

            else {
                arr[k] = right[j++];
                invCount += (n1 - i);
            }
            k++;
        }

        // copy remaining elements
        while (i < n1) arr[k++] = left[i++];
        while (j < n2) arr[k++] = right[j++];

        return invCount;
    }

    int countInv(vector<int>& arr, int l, int r) {
        int invCount = 0;
        if (l < r) {
            int m = (r + l) / 2;
            invCount += countInv(arr, l, m);
            invCount += countInv(arr, m + 1, r);
            invCount += countAndMerge(arr, l, m, r);
        }
        return invCount;
    }

    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        return countInv(arr, 0, n - 1);
    }
};

int main() {
    vector<int> arr = {4, 3, 2, 1};

    Solution sol;
    cout << sol.inversionCount(arr);
    return 0;
}