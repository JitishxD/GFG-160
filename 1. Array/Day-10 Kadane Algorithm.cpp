#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum = arr[0];
        int currSum = arr[0];
        for(int i=1; i<arr.size(); i++){
            currSum = max(arr[i], currSum+arr[i]);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};

    cout << sol.maxSubarraySum(arr) << endl;
    return 0;
}