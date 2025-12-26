#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefProduct(n), suffProduct(n), ans(n);

        prefProduct[0] = 1;
        for (int i = 1; i < n; i++)
            prefProduct[i] = arr[i - 1] * prefProduct[i - 1];

        suffProduct[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--)
            suffProduct[j] = arr[j + 1] * suffProduct[j + 1];

        for (int i = 0; i < n; i++) ans[i] = prefProduct[i] * suffProduct[i];

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> result = sol.productExceptSelf(arr);
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}