#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        vector<int> res;
        int n = arr.size();
        unordered_set<int> um;
        
        for(int i=0; i<n; i++){
            int com = target - arr[i];
            if(um.find(com) != um.end()) return true;
            
            um.insert(arr[i]);
        }
        
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {10, 15, 3, 7};
    int target = 17;
    cout << (sol.twoSum(arr, target)? "Pair found" : "No pair found") << endl;
    return 0;
}