#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    double power(double b, int e) { return pow(b, e); }
};

int main() {
    Solution sol;
    cout << sol.power(2.0, 10) << endl;
    return 0;
}