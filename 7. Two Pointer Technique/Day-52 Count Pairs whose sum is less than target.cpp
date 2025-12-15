#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

// User function Template for C++
class Solution {
   public:
    int countPairs(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size() - 1;
        int count = 0;

        while (l < r) {
            int sum = arr[l] + arr[r];

            if (sum < target) {
                count += r - l;
                l++;
            } else {
                r--;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 4, 5, 7, 9};
    int target = 12;
    cout << "Number of pairs with sum less than " << target
         << " is: " << sol.countPairs(arr, target) << endl;
    return 0;
}
