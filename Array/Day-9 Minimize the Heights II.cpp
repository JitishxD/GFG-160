#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int getMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int res = arr[n - 1] - arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] - k < 0) continue;
            /*
            To make the smallest tower smaller, we should do arr[0] - k
            To make the largest tower larger, we should do arr[n-1] + k
            That would increase the gap — which is opposite of what we want.
            */

            /*
            arr[0] + k: smallest tower (increased)
            arr[i] - k: kya pata isko(second tower) -k karne se ye minH hojaye

            arr[i-1]+k: kya pata isko(last tower) increase karne se ye maxH se
            bhi bada hojaye arr[n-1]-k: tallest tower (decreased)
            */
            int minH = min(arr[0] + k, arr[i] - k);
            int maxH = max(arr[i - 1] + k, arr[n - 1] - k);
            res = min(res, maxH - minH);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 9, 12, 16, 20};
    int k = 3;
    cout << sol.getMinDiff(arr, k) << endl;
    return 0;
}