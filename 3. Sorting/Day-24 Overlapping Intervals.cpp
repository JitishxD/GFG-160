#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        //sort on basis of start value (arr[i][0])
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        
        for(int i=1; i<arr.size(); i++){
            vector<int>& curr = arr[i];
            vector<int>& last = ans.back();
            
            if(curr[0] <= last[1]){
                last[1] = max(last[1], curr[1]);
            } else {
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr = {{4, 8}, {7, 9}, {5, 6}, {6, 10}};
    vector<vector<int>> mergedIntervals = sol.mergeOverlap(arr);
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}