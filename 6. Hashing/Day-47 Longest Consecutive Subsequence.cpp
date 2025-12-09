#include <iostream>
#include <vector>

#include <unordered_set>

using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> um;
        int ans = 0;

        for (int val : arr) um.insert(val);

        for (int val : arr) {
            if (um.find(val) != um.end() && um.find(val - 1) == um.end()) {
                int cur = val, count = 0;
                while (um.find(cur) != um.end()) {
                    um.erase(cur);
                    cur++;
                    count++;
                }

                ans = max(ans, count);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(arr) << endl;
    return 0;
}