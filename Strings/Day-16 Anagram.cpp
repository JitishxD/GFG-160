#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool areAnagrams(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;

        unordered_map<char, int> freq;

        for (char c : s1) {
            freq[c] += 1;
        }
        for (char c : s2) {
            auto it = freq.find(c);
            if (it == freq.end()) return false;
            // check the count after decrementing it
            if (--(it->second) < 0) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s1 = "listen";
    string s2 = "silent";
    if (sol.areAnagrams(s1, s2)) {
        cout << s1 << " and " << s2 << " are anagrams." << endl;
    } else {
        cout << s1 << " and " << s2 << " are not anagrams." << endl;
    }
    return 0;
}