#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> ans;
        int i =0;
        int n = intervals.size();
        
        //As non-overlapping intervals
        //push all intervals come before new interval
        while(i<n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        
        //checking more overlapping intervals 
        //and merge them into newInterval
        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        //push the newInterval
        ans.push_back(newInterval);
        
        //now push rest of the intervals
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    vector<vector<int>> result = sol.insertInterval(intervals, newInterval);
    for( auto interval : result){
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    
    return 0;
}