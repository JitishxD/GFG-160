#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void reverseArr(vector<int>& arr, int left, int right){
        while(left<right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;
        reverseArr(arr, 0, d-1);
        reverseArr(arr, d, n-1);
        reverseArr(arr, 0, n-1);
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;
    sol.rotateArr(arr, d);
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}