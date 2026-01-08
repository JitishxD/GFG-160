#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void nQueenUtil(int j, int n, vector<int> &board, vector<bool> &rows, 
    	vector<bool> &diag1, vector<bool> &diag2, vector<vector<int>> &res) {
    	
        if (j > n) {
          	// A solution is found
            res.push_back(board);
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!rows[i] && !diag1[i + j] && !diag2[i - j + n]) {
    
                // Place queen
                rows[i] = diag1[i + j] = diag2[i - j + n] = true;
                board.push_back(i);
    
                // Recurse to the next column
                nQueenUtil(j + 1, n, board, rows, diag1, diag2, res);
    
                // Remove queen (backtrack)
                board.pop_back();
                rows[i] = diag1[i + j] = diag2[i - j + n] = false;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> board;
    
        vector<bool> rows(n + 1, false);
    
        vector<bool> diag1(2 * n + 1, false);
        vector<bool> diag2(2 * n + 1, false);
    
        nQueenUtil(1, n, board, rows, diag1, diag2, res);
        return res;
    }
};

int main(){
    Solution sol;
    int n = 4;
    vector<vector<int>> result = sol.nQueen(n);
    for (const auto &solution : result) {
        for (int col : solution) {
            cout << col << " ";
        }
        cout << endl;
    }
    
    return 0;
}