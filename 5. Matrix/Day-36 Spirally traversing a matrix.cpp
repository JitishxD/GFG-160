#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        vector<int> ans;
        while (top <= bottom && left <= right) {
            // print top row
            for (int i = left; i <= right; i++) {
                ans.push_back(mat[top][i]);
            }
            top++;

            // print right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(mat[i][right]);
            }
            right--;

            // print bottom row if any
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }

            // print left column if any
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    Solution sol;
    vector<int> ans = sol.spirallyTraverse(matrix);
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}