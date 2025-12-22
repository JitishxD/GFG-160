#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxWater(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        int ans = 0;
        while (l < r) {
            int water = min(arr[l], arr[r]) * (r - l);
            ans = max(ans, water);

            if (arr[l] < arr[r]) l++;
            else r--;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1, 5, 4, 3};
    cout << sol.maxWater(height) << endl;

    return 0;
}