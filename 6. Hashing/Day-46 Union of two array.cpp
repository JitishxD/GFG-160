#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> us;
        vector<int> ans;

        for (int i = 0; i < a.size(); i++) {
            us.insert(a[i]);
        }

        for (int i = 0; i < b.size(); i++) {
            us.insert(b[i]);
        }

        for (auto it : us) {
            ans.push_back(it);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, 8, 9};
    vector<int> result = sol.findUnion(a, b);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}