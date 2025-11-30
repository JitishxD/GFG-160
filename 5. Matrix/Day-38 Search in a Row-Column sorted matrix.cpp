#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool binarySearch(vector<int>& row, int x){
        int n = row.size();
        int start=0;
        int end=n-1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(row[mid]==x) return true;
            else if(row[mid]>x) end = mid-1;
            else start=mid+1;
        }
        
        return false;
    }
    bool matSearch(vector<vector<int>> &mat, int x) {
        for(int i=0; i<mat.size(); i++){
            bool searchh = binarySearch(mat[i], x);
            if(searchh) return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target = 3;
    bool found = sol.matSearch(matrix, target);
    cout<< (found ? "Element found" : "Element not found") << endl;
    return 0;
}