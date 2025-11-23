#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int peakElementBrute(vector<int> &arr) {
        int r, l;
        int n = arr.size();
        
        if (n-1 == 0){
            return 0;
        }
        
        // as it would be always greater than negative infinity.
        if(arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2]) return n-1;
        
        for(int i=1; i<n-1; i++){
            r = i-1;
            l = i+1;
            
            if(arr[i] > arr[r] && arr[i] > arr[l]){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 3, 20, 4, 1, 0, 6, 5};
    int peakIndex = sol.peakElementBrute(arr);
    cout << "Peak element index Brute: " << peakIndex << endl;


    return 0;
}