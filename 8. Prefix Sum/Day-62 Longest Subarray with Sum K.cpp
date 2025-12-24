#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumIndex;
        int prefixSum = 0;
        int maxLen = 0;
        prefixSumIndex[0] = -1;
        for(int i=0; i<arr.size(); i++){
            prefixSum += arr[i];
            int comp = prefixSum - k;

            if (prefixSum == k) maxLen = max(maxLen, i+1);
            
            if (prefixSumIndex.find(comp) != prefixSumIndex.end()) {  
                maxLen = max(maxLen, i-prefixSumIndex[comp]);  
            }  
            
            if (prefixSumIndex.find(prefixSum) == prefixSumIndex.end()) {
                prefixSumIndex[prefixSum] = i;
            }
        }
        return maxLen;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    cout << sol.longestSubarray(arr, k) << endl;
    return 0;
}