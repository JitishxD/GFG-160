#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> constructLps(string& pat) {
        int len = 0;
        int n = pat.length();
        vector<int> lps(n);

        lps[0] = 0;

        int i = 1;
        while (i < n) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }

            else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    bool areRotations(string& s1, string& s2) {
        // Now txt contain all possible rotaion on s1
        // as a substring
        string txt = s1 + s1;
        string pat = s2;

        int n = txt.length();
        int m = pat.length();

        vector<int> lps = constructLps(pat);

        int i = 0;
        int j = 0;
        while (i < n) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }

            if (j == m) {
                return true;
            }

            else if (i < n && pat[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "ABCD";
    string s2 = "CDAB";
    cout << sol.areRotations(s1, s2) << endl;
    return 0;
}