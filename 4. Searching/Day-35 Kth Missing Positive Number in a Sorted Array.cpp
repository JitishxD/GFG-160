#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int kthMissing(vector<int>& arr, int k) {
        int start = 0, end = arr.size() - 1;
        int res = arr.size() + k;
    
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] > mid + k) {
                res = mid + k;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    
        return res;
    }
};

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    Solution sol;
    cout << sol.kthMissing(arr, k);
    return 0;
}