#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    vector<vector<int>> findTriplets(vector<int>& arr) {
        unordered_map<int, vector<int>> um;

        vector<vector<int>> ans;

        for (int j = 0; j < arr.size(); j++) {
            for (int k = j + 1; k < arr.size(); k++) {
                int val = -1 * (arr[j] + arr[k]);

                if (um.find(val) != um.end()) {
                    for (auto i : um[val]) {
                        ans.push_back({i, j, k});
                    }
                }
            }
            um[arr[j]].push_back(j);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> triplets = sol.findTriplets(arr);

    cout << "Triplets with zero sum (by indices):" << endl;
    for (const auto& triplet : triplets) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}