#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int myAtoi(string& s) {
        int sign = 1, res = 0, i = 0;

        //handle whitespaces
        while (s[i] == ' ') {
            i++;
        }

        //handle sign
        if (s[i] == '-' || s[i] == '+') {
            if (s[i++] == '-') sign = -1;
        }

        //handle digits and overflow, underflow
        while (s[i] >= '0' && s[i] <= '9') {
            if (res > INT_MAX / 10 ||
                (res == INT_MAX / 10 && s[i] - '0' > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            //Append current digit to the result
            res = 10 * res + (s[i++] - '0');
        }
        return res * sign;
    }
};

int main() {
    Solution sol;
    string str = "   -42";
    cout << sol.myAtoi(str) << endl;
    return 0;
}