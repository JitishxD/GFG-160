#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int countPairs(vector<int>& arr, int target) {
        unordered_map<int, int> um;
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            int comp = target - arr[i];
            
            if (um.find(comp) != um.end()) {
                count += um[comp];
            }

            um[arr[i]]++;
        }

        printMap(um);

        return count;
    }

    void printMap(const unordered_map<int, int>& um) {
        for (const auto& pair : um) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 5, 7, -1, 5};
    int target = 6;
    cout << sol.countPairs(arr, target) << endl;
    return 0;
}