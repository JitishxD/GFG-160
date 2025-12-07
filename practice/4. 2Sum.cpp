#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSumHashMap(vector<int>& arr, int target) {
        unordered_map<int, int> um;
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (um.find(target - arr[i]) != um.end())
                return {um[target - arr[i]], i};
            // store the index of curr elem
            um[arr[i]] = i;
        }
        return {};
    }

    vector<int> twoSumTwoPointer(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> a;

        // pair: value, original index
        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        int left = 0, right = n - 1;

        while (left < right) {
            int sum = a[left].first + a[right].first;

            if (sum == target) return {a[left].second, a[right].second};
            else if (sum < target) left++;
            else right--;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 2, 4};
    int target = 6;

    vector<int> result = sol.twoSumHashMap(arr, target);
    cout << "Indices (HashMap): ";
    for (int index : result) cout << index << " ";
    cout << endl;

    // Note: twoSumTwoPointer requires sorted array; using original array for
    // demo
    result = sol.twoSumTwoPointer(arr, target);
    cout << "Indices (Two Pointer): ";
    for (int index : result) cout << index << " ";
    cout << endl;

    return 0;
}