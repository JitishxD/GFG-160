#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> a, vector<int> b) {
                 return a[1] < b[1];
             });
        
        int count = 0;
        int i = 1;
        int n = intervals.size();
        
        int lastEnd = intervals[0][1];

        for(int i=1; i<n; i++){
            if(lastEnd > intervals[i][0]){
                count++;
            } else {
                lastEnd = intervals[i][1];
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> intervals2 = {{13, 14}, {13, 19}, {6, 17},
                                      {9, 10},  {5, 17},  {9, 15},
                                      {7, 12},  {12, 13}, {13, 15}};

    cout << sol.minRemoval(intervals) << endl;
    cout << sol.minRemoval(intervals2) << endl;

    return 0;
}