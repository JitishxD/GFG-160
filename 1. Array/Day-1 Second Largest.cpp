#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // 1 <= arr[i] <= 10^5
        int firstLargest = -1, secondLargest;
        for (int i: arr){
            if (i > firstLargest){
                secondLargest = firstLargest;
                firstLargest = i;
            }else if (i < firstLargest && i > secondLargest) {
                secondLargest = i;
            }
        }
        return secondLargest;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> arr1 = {12, 35, 1, 10, 34, 1};
    cout << "Test case 1 result: " << solution.getSecondLargest(arr1) << endl;
    
    // Test case 2
    vector<int> arr2 = {10, 5, 10};
    cout << "Test case 2 result: " << solution.getSecondLargest(arr2) << endl;
    
    // Test case 3
    vector<int> arr3 = {10, 10, 10};
    cout << "Test case 3 result: " << solution.getSecondLargest(arr3) << endl;
    
    return 0;
}