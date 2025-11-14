#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end(), greater<int>());
    
        int n = citations.size();
        int idx = 0;
    
    	while(idx < n && citations[idx] > idx) {
            idx += 1;
        }
        return idx;
    }
};

int main(){
    Solution sol;
    vector<int> citations = {3, 0, 5, 3, 0};
    cout << sol.hIndex(citations) << endl;
    return 0;
}