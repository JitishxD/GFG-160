#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class Solution {
   public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        sort(arr.begin(), arr.end());
        int count = 0;

        // Fix the largest side
        for (int i = n - 1; i >= 2; i--) {
            int l = 0, r = i - 1;

            while (l < r) {
                if (arr[l] + arr[r] > arr[i]) {
                    count += (r - l);
                    r--;
                } else {
                    l++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 6, 3, 7};
    vector<int> arr1 = {10, 21, 22, 100, 101, 200, 300};
    vector<int> arr2 = {1, 2, 3};
    cout << "Number of possible triangles: " << sol.countTriangles(arr) << endl;
    cout << "Number of possible triangles: " << sol.countTriangles(arr1)
         << endl;
    cout << "Number of possible triangles: " << sol.countTriangles(arr2)
         << endl;
    return 0;
}