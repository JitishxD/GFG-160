#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> subarraySum(vector<int>& arr, int target) {
        int s = 0, e = 0;
        vector<int> res;

        int curr = 0;
        for (int i = 0; i < arr.size(); i++) {
            curr += arr[i];

            if (curr >= target) {
                e = i;
                while (curr > target && s < e) {
                    curr -= arr[s];
                    ++s;
                }

                if (curr == target) {
                    res.push_back(s + 1);
                    res.push_back(e + 1);
                    return res;
                }
            }
        }
        return {-1};
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;
    vector<int> result = sol.subarraySum(arr, target);
    for (int index : result) {
        cout << index << " ";
    }
    cout << "\n";
    return 0;
}