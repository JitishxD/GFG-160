#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    char nonRepeatingChar(string& s) {
        char curr = s[0];
        int arr[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            curr = s[i];
            arr[curr - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            curr = s[i];
            if (arr[curr - 'a'] == 1) {
                return curr;
            }
        }

        return '$';
    }
};

int main() {
    Solution sol;
    string s = "aabbccddeef";
    char result = sol.nonRepeatingChar(s);
    cout << "First non-repeating character: " << result << endl;
    return 0;
}