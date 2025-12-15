#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> res;
        int minDiff = INT_MAX;
    
        int l = 0, r = n - 1;
    
        while (l < r) {
            int currSum = arr[l] + arr[r];
    
            if (abs(target - currSum) < minDiff) {
                minDiff = abs(target - currSum);
                res = {arr[l], arr[r]};
            }
    
            if (currSum < target) l++;
            else if (currSum > target) r--;
    
            else return res;
        }
    
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {10, 22, 28, 29, 30, 40};
    int target = 54;
    vector<int> result = sol.sumClosest(arr, target);
    cout << "The pair whose sum is closest to target " << target << " is: ";
    cout << result[0] << " and " << result[1] << endl;
    return 0;
}