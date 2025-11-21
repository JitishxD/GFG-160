#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMin(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if(arr[i] > arr[i+1]){
                return arr[i+1];
            }
        }
        return arr[0];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    cout << "Minimum element in the sorted and rotated array is: "
         << sol.findMin(arr) << endl;
    return 0;
}