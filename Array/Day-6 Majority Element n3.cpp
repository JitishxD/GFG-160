#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> res;
    
        for (int ele : arr)
            freq[ele]++;
    
        for (auto i : freq) {
            int ele = i.first;
            int count = i.second;

            if (count > n / 3)
                res.push_back(ele);
        }
    
        if (res.size() == 2 && res[0] > res[1])
            swap(res[0], res[1]);
            
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    for(int ele : sol.findMajority(arr)){
        cout << ele << " ";
    }
    return 0;
}