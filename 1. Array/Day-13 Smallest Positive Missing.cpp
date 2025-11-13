#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        vector<bool> vis(n, false);
        
        for(int i=0; i<n; i++){
            if(arr[i]>0 && arr[i]<=n){
                vis[arr[i]-1] = true;
            }
        }
        
        for(int i=0; i<=n; i++){
            if(!vis[i]){
                return i+1;
            }
        }
        
        return n+1;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {2, -3, 4, 1, 1, 7};
    vector<int> arr2 = {5, 3, 2, 5, 1};
    vector<int> arr3 = {-8, 0, -1, -4, -3};
    cout << sol.missingNumber(arr1) << endl;
    cout << sol.missingNumber(arr2) << endl;
    cout << sol.missingNumber(arr3) << endl;
    return 0;
}