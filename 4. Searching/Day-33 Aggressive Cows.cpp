#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& stalls, int k, int dist) {
    // place first cow at 0th index
    int cnt = 1;
    int prev = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        // if the current stall is at least dist away
        // from the previous one place the cow here
        if (stalls[i] - prev >= dist) {
            prev = stalls[i];
            cnt++;
        }
    }

    // return true if all cows are placed.
    return (cnt >= k);
}

int aggressiveCows(vector<int>& stalls, int k) {

    sort(stalls.begin(), stalls.end());
    int res = 0;

    int start = 1;
    int end = stalls.back() - stalls[0];
    while (start <= end) {
        int mid = start + (end - start) / 2;

        // If the mid ditance is possible, update
        // the result and search for larger ditance
        if (check(stalls, k, mid)) {
            res = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return res;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << aggressiveCows(stalls, k) << endl;
    return 0;
}