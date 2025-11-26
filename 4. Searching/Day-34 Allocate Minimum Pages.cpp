#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    bool check(vector<int>& arr, int k, int pageLimit) {
        int cnt = 1;
        int pageSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (pageSum + arr[i] > pageLimit) {
                cnt++;
                pageSum = arr[i];
            } else {
                pageSum += arr[i];
            }
        }
        return (cnt <= k);
    }

    int findPages(vector<int>& arr, int k) {
        if (k > arr.size()) return -1;

        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        int res = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (check(arr, k, mid)) {
                res = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return res;
    }
};

int main() {
    vector<int> arr = {16, 8, 5, 3, 2, 4};
    int k = 2;
    Solution sol;
    cout << sol.findPages(arr, k);
    return 0;
}