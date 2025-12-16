#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int countPairs(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0, r = n - 1;
        int count = 0;

        while (l < r) {
            int cs = arr[l] + arr[r];
            if (cs > target) r--;
            else if (cs < target) l++;
            else {
                int ele1 = arr[l], ele2 = arr[r];
                int count1 = 0, count2 = 0;

                while (l <= r && arr[l] == ele1) {
                    count1++;
                    l++;
                }

                while (l <= r && arr[r] == ele2) {
                    count2++;
                    r--;
                }

                if (ele1 == ele2) count += (count1 * (count1 - 1)) / 2;
                else count += count1 * count2;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {-1, 1, 5, 5, 7};
    int target = 6;
    cout << "Number of pairs with sum equal to " << target
         << " is: " << sol.countPairs(arr, target) << endl;
    return 0;
}