#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string trimLeadingZeros(const string& s) {
        size_t pos = s.find('1');
        return (pos == string::npos) ? "0" : s.substr(pos);
    }

    string addBinary(string& s1, string& s2) {
        // Remove leading zeros
        s1 = trimLeadingZeros(s1);
        s2 = trimLeadingZeros(s2);

        // Ensure s1 is always the larger string
        if (s1.length() < s2.length()) {
            //swap
            return addBinary(s2, s1);
        }

        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int carry = 0;

        while (i >= 0) {
            int sum = (s1[i] - '0') + carry;

            if (j >= 0) {
                sum += (s2[j] - '0');
                j--;
            }

            s1[i] = (sum % 2) + '0';
            carry = sum / 2;
            i--;
        }

        // If carry still exists, prepend '1'
        if (carry) {
            s1.insert(s1.begin(), '1');
        }

        return s1;
    }
};

int main() {
    Solution sol;
    string s1 = "1010";
    string s2 = "1011";
    cout << sol.addBinary(s1, s2) << endl;
    return 0;
}