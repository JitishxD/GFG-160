#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        unordered_map<int, int> mp;
        int preSum = 0;
        int ans = 0;
    
        for (int i = 0; i < arr.size(); i++) {
            preSum += (arr[i] == 0) ? -1 : 1;
    
            if (preSum == 0) ans = i + 1;
    
            if (mp.find(preSum) != mp.end()) ans = max(ans, i - mp[preSum]);
    
            else mp[preSum] = i;
        }
    
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 0, 1, 1, 1, 0, 0};
    cout << sol.maxLen(arr) << endl;
    return 0;
}