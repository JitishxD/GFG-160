#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.length();
        int l=0, r=0;
        int maxLen = 0;
        vector<bool> vis(26, false);
        
        while(r<n){
            while(vis[s[r] - 'a'] == true){
                vis[s[l] - 'a'] = false;
                l++;
            }
            
            //mark curr char visited
            vis[s[r] - 'a'] = true;
            
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        
        return maxLen;
    }
};


int main(){
    Solution sol;
    string s = "geeksforgeeks";
    cout << sol.longestUniqueSubstr(s) << endl;
    return 0;
}