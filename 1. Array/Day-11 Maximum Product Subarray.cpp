#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int maxProd = INT_MIN;
        int leftToRight = 1, rightToLeft = 1;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            
            if (leftToRight == 0){
                leftToRight = 1;
            }
            
            if (rightToLeft == 0){
                rightToLeft = 1;
            }
            
            leftToRight *= arr[i];
            
            int j = n-1-i;
            
            rightToLeft *= arr[j];
            
            maxProd = max({leftToRight, rightToLeft, maxProd});
        }
        
        return maxProd;
    }
};

int main(){
    Solution sol;

    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    cout<< sol.maxProduct(arr) << endl;
    
    return 0;
}