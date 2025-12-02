#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool binarySearch(vector<int>& row, int x) {
        int n = row.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (row[mid] == x)
                return true;
            else if (row[mid] > x)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return false;
    }

    bool searchMatrixOptimised(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size();

        int start = 0, end = n * m - 1;
        while (start <= end) {
            int mid = (start + end) / 2;

            // find row and column of element at mid index
            int row = mid / m;
            int col = mid % m;

            if (mat[row][col] == x) return true;
            else if (mat[row][col] > x) end = mid - 1;
            else start = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int x) {
        for (int i = 0; i < mat.size(); i++) {
            bool searchh = binarySearch(mat[i], x);
            if (searchh) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int target = 14;
    cout << (sol.searchMatrix(matrix, target) ? "Element found"
                                              : "Element not found")
         << endl;
    return 0;
}