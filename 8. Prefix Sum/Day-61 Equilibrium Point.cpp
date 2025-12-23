#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int prefixSum=0, suffixSum=0;
        int totalSum = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            totalSum += arr[i];
        }
        
        for(int i=0; i<n; i++){
            suffixSum = totalSum-prefixSum-arr[i];
            if(prefixSum == suffixSum) return i;
            
            prefixSum += arr[i];
        }
        
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 2, 0, 3};
    cout << sol.findEquilibrium(arr) << endl;
    
    return 0;
}