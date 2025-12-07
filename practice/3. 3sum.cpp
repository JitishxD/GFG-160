#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;

            while (l < r) {
                int cs = nums[i] + nums[l] + nums[r];
                if (cs == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    // skip duplicates
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (cs < 0) l++;
                else r--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> triplets = sol.threeSum(arr);

    // Output the triplets
    for (const auto& triplet : triplets) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}