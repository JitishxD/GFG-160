#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void pushZerosToEnd(vector<int>& arr) {
        int nz = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                int temp = arr[i];
                arr[i] = arr[nz];
                arr[nz] = temp;
                nz++;
            }
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {1, 2, 0, 4, 3, 0, 5, 0};
    sol.pushZerosToEnd(arr1);
    for (int x : arr1) cout << x << " ";
    cout << endl;
    return 0;
}