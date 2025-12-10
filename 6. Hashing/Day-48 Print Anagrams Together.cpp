#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    void printAnagramGroups(const vector<vector<string>>& groups) {
        for (const auto& group : groups) {
            for (const auto& str : group) {
                cout << str << " ";
            }
            cout << endl;
        }
    }

    vector<vector<string>> anagramsBruteForce(vector<string>& arr) {
        unordered_map<string, vector<int>> um;

        for (int i = 0; i < arr.size(); i++) {
            string sorted_str = arr[i];
            sort(sorted_str.begin(), sorted_str.end());
            um[sorted_str].push_back(i);
        }

        vector<vector<string>> result;
        for (auto& it : um) {
            vector<string> group;
            for (int index : it.second) {
                group.push_back(arr[index]);
            }
            result.push_back(group);
        }

        return result;
    }

    string getHash(string& s, int MAX_CHAR = 26) {
        string hash;
        vector<int> freq(MAX_CHAR, 0);

        // Count frequency of each character
        for (char ch : s) freq[ch - 'a'] += 1;

        // Append the frequency to construct the hash
        for (int i = 0; i < MAX_CHAR; i++) {
            hash.append(to_string(freq[i]));
            hash.append("$");
        }

        // cout << "Hash for string '" << s << "': " << hash << endl;

        return hash;
    }

    vector<vector<string>> anagramsOptimised(vector<string>& arr) {
        vector<vector<string>> res;
        unordered_map<string, int> um;
        for (int i = 0; i < arr.size(); i++) {
            string currStrHash = getHash(arr[i]);

            // If currStrHash is not present in the hash map, add
            // an empty group (vector) in the result
            if (um.find(currStrHash) == um.end()) {
                //res.size() gives the index of the new group
                um[currStrHash] = res.size();
                res.push_back({});
            }

            // Insert the string in its correct group
            res[um[currStrHash]].push_back(arr[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> arr = {"cat", "dog", "tac", "god", "act"};
    sol.printAnagramGroups(sol.anagramsBruteForce(arr));

    cout << "Using Optimised Method:" << endl;
    sol.printAnagramGroups(sol.anagramsOptimised(arr));

    return 0;
}