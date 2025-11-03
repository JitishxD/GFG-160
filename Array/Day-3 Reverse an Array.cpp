#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void reverseArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {1, 4, 3, 2, 6, 5};
    sol.reverseArray(arr1);
    for (int x : arr1) cout << x << " ";
    cout << endl;

    return 0;
}