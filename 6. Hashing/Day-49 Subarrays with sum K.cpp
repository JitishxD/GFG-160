#include <iostream>
#include <vector>

#include <unordered_map>

using namespace std;

class Solution {
   public:
    int cntSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSums;

        int res = 0;
        int currSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            currSum += arr[i];

            if (currSum == k) res++;

            if (prefixSums.find(currSum - k) != prefixSums.end())
                res += prefixSums[currSum - k];

            prefixSums[currSum]++;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 1};
    int k = 2;

    cout << sol.cntSubarrays(arr, k) << endl;

    return 0;
}