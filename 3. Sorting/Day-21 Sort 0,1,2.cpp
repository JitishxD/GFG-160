#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void sort012(vector<int>& arr) {
        int nz = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                swap(arr[i], arr[nz]);
                // cout << nz << endl;

                nz++;
            }
        }

        for (int i = nz; i < arr.size(); i++) {
            if (arr[i] == 1) {
                swap(arr[i], arr[nz]);
                // cout << nz << endl;

                nz++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {0, 2, 1, 2, 0, 1, 0};
    vector<int> arr2 = {1, 2, 1};
    sol.sort012(arr2);

    for (int num : arr2) {
        cout << num << " ";
    }
    return 0;
}