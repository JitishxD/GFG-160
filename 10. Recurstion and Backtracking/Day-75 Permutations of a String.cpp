#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void getPermutations(int n, string& curr, unordered_map<char, int>& count,
                         vector<string>& ans) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for (pair<char, int> it : count) {
            char c = it.first;
            int freq = it.second;

            if (freq == 0) continue;

            curr.push_back(c);
            count[c]--;

            getPermutations(n, curr, count, ans);

            curr.pop_back();
            count[c]++;
        }
    }

    vector<string> findPermutation(string s) {
        vector<string> ans;
        unordered_map<char, int> count;

        for (char c : s) count[c]++;

        string curr = "";
        getPermutations(s.size(), curr, count, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "aabc";
    vector<string> permutations = sol.findPermutation(s);

    cout << "Permutations of the string \"" << s << "\":" << endl;
    for (const string& perm : permutations) {
        cout << perm << endl;
    }

    return 0;
}