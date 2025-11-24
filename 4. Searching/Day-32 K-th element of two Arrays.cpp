#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size(), m = b.size();
        vector<int> ans;
        
        int i=0, j=0;
        
        while(k--){
            if (i == n) {
                ans.push_back(b[j]);
                j++;
                continue;
            }
            if (j == m) {
                ans.push_back(a[i]);
                i++;
                continue;
            }
            
            if(a[i]>b[j]) { 
                ans.push_back(b[j]);
                j++;
            }
            else { 
                ans.push_back(a[i]);
                i++;
            }
            
        }
        
        return ans.back();
        
    }
};

int main(){
    Solution sol;
    vector<int> a = {2, 3};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    cout << sol.kthElement(a, b, k) << endl;
    return 0;
}