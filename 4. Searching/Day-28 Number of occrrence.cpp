#include <iostream>
#include <vector>

using namespace std;

// Using binary search!
class Solution1 {
   public:
    int boundSearch(vector<int>& arr, int target, bool isLower) {
        int start = 0, end = arr.size() - 1;
        int n = arr.size();
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isLower) {
                // lower_bound: first index where arr[mid] >= target
                if (arr[mid] >= target) {
                    n = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                // upper_bound: first index where arr[mid] > target
                if (arr[mid] > target) {
                    n = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return n;
    }

    int countFreq(vector<int>& arr, int target) {
        int l = boundSearch(arr, target, true);   // lower bound
        int r = boundSearch(arr, target, false);  // upper bound
        return r - l;
    }
};

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int count = 0;
        for(int i: arr){
            if(target==i){
                count++;
            }
        }
        return count;
    }
};


int main() {
    Solution sol;
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;
    cout << "Frequency of " << target << " is: " << sol.countFreq(arr, target) << endl;

    Solution1 sol1;
    cout << "Frequency of " << target << " using binary search is: " << sol1.countFreq(arr, target) << endl;

    return 0;
}