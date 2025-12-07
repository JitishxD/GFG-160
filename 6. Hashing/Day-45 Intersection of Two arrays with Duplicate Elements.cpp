#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        unordered_map<int, vector<int>> um;
        int n = a.size(), m = b.size();
        unordered_set<int> s;

        for (int i = 0; i < n; i++) {
            um[a[i]].push_back(i);
        }
        for (int i = 0; i < m; i++) {
            if (um.find(b[i]) != um.end() && !um[b[i]].empty()) {
                s.insert(b[i]);
                um[b[i]].pop_back();
            }
        }
        return vector<int>(s.begin(), s.end());
    }

    vector<int> intersectOptimal(vector<int>& a, vector<int>& b) {
        unordered_set<int> um(a.begin(), a.end());
        vector<int> s;

        for (int i = 0; i < b.size(); i++) {
            if (um.find(b[i]) != um.end()) {
                s.push_back(b[i]);
                um.erase(b[i]);
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 2, 1, 3, 1};
    vector<int> b = {3, 1, 3, 4, 1};
    vector<int> result1 = sol.intersect(a, b);
    vector<int> result2 = sol.intersectOptimal(a, b);

    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}