#include <iostream>
#include <vector>

#include <unordered_map>

using namespace std;

class Solution {
   public:
    long subarrayXor(vector<int>& arr, int k) {
        long res = 0;
        unordered_map<int, int> mp;
        int prefXOR = 0;

        for (int val : arr) {
            prefXOR ^= val;
            res = res + mp[prefXOR ^ k];

            if (prefXOR == k) res++;

            mp[prefXOR]++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "Number of subarrays with given XOR " << k << " is: " << sol.subarrayXor(arr, k) << endl;
    return 0;
}