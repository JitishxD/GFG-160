#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void mergeArraysNaive(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();

        for (int i = 0; i < n; i++) {
            if (a[i] > b[0]) {
                swap(a[i], b[0]);

                // move this new elem to correct position
                int k = 0;
                while (k + 1 < m && b[k] > b[k + 1]) {
                    swap(b[k], b[k + 1]);
                    k++;
                }
            }
        }
    }

    void mergeArraysOptimalGapShellSort(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int gap = (n + m + 1) / 2;

        while (gap > 0) {
            int i = 0, j = gap;

            while (j < n + m) {
                // If both pointers are in the first array a[]
                if (j < n && a[i] > a[j]) {
                    swap(a[i], a[j]);
                }

                // If first pointer is in a[] and
                // the second pointer is in b[]
                else if (i < n && j >= n && a[i] > b[j - n]) {
                    swap(a[i], b[j - n]);
                }

                // Both pointers are in the second array b
                else if (i >= n && b[i - n] > b[j - n]) {
                    swap(b[i - n], b[j - n]);
                }
                i++;
                j++;
            }

            // After operating for gap of 1 break the loop
            if (gap == 1) break;

            // Calculate the next gap
            gap = (gap + 1) / 2;
        }
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 4, 7, 8, 10};
    vector<int> b = {2, 3, 9};
    sol.mergeArraysNaive(a, b);
    // sol.mergeArraysOptimalGapShellSort(a, b);
    cout << "Array A: ";
    for (int num : a) cout << num << " ";
    cout << "\nArray B: ";
    for (int num : b) cout << num << " ";
    cout << endl;
    return 0;
}