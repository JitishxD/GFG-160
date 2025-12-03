#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    static void displayMat(vector<vector<int>>& mat) {
        cout << endl;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    };

    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> points;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    points.push_back({i, j});
                }
            }
        }

        for (vector<int> point : points) {
            int x = point[0];
            int y = point[1];
            // set row to zero
            for (int cols = 0; cols < m; cols++) mat[x][cols] = 0;
            // set col to zero
            for (int rows = 0; rows < n; rows++) mat[rows][y] = 0;
        }
    }

    void setMatrixZeroesOptimized(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int c0 = 1;

        Solution::displayMat(mat);

        // Traverse the arr and mark first cell of each row and column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    // mark i-th row
                    mat[i][0] = 0;

                    // mark j-th column
                    if (j == 0)
                        c0 = 0;
                    else
                        mat[0][j] = 0;
                }
            }
        }

        Solution::displayMat(mat);

        // Traverse and mark the matrix from (1, 1) to (n - 1, m - 1)
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                // Check for col & row
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        Solution::displayMat(mat);

        // Mark the first row
        if (mat[0][0] == 0) {
            for (int j = 0; j < m; j++) mat[0][j] = 0;
        }

        Solution::displayMat(mat);

        // Mark the first column
        if (c0 == 0) {
            for (int i = 0; i < n; i++) mat[i][0] = 0;
        }

        cout << "Final Matrix: ";
        Solution::displayMat(mat);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 0, 6}, {7, 8, 9}};
    sol.setMatrixZeroesOptimized(matrix);
    Solution::displayMat(matrix);
    return 0;
}