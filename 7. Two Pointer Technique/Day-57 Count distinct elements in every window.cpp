#include <iostream>
#include <vector>

#include <unordered_map>

using namespace std;

class Solution {
   public:
    vector<int> countDistinct(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        unordered_map<int, int> freq;

        for (int i = 0; i < k; i++) freq[arr[i]] += 1;

        ans.push_back(freq.size());

        for (int i = k; i < n; i++) {
            freq[arr[i]] += 1;
            freq[arr[i - k]] -= 1;

            if (freq[arr[i - k]] == 0) freq.erase(arr[i - k]);

            ans.push_back(freq.size());
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    vector<int> ansult = sol.countDistinct(arr, k);
    for (int count : ansult) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}