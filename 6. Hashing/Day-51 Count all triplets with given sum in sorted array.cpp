#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        int res = 0;

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;

            while (l < r) {
                int cs = arr[i] + arr[l] + arr[r];

                if (cs < target) l++;
                else if (cs > target) r--;
                
                else if (cs == target) {
                    int ele1 = arr[l], ele2 = arr[r];
                    int count1 = 0, count2 = 0;

                    while (l <= r && arr[l] == ele1) {
                        l++;
                        count1++;
                    }

                    while (l <= r && arr[r] == ele2) {
                        r--;
                        count2++;
                    }

                    // count1 C 2
                    if (ele1 == ele2) res += (count1 * (count1 - 1)) / 2;

                    else res += (count1 * count2);
                }
            }
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {-3, -1, -1, 0, 1, 2};
    int target = -2;
    cout << "Number of triplets with sum " << target << " is: " << sol.countTriplets(arr, target) << endl;

    return 0;
}