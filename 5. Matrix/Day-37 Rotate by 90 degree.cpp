#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rotateMatrix(vector<vector<int>> &mat){
      	int n = mat.size();
      
        // n/2 squares or cycles are there
        for (int i = 0; i < n / 2; i++) {
          
            //P1(i, j), P2(j, n-1-i), P3(n-1-i, n-1-j) 
            //and P4(n-1-j, i), now rotate these 4 elements, 
            //temp<--P1, P1 <--P2, P2<--P3, P3<--P4, P4<--temp.
            for (int j = i; j < n - i - 1; j++) {
              	
                int temp = mat[i][j];
                mat[i][j] = mat[j][n - 1 - i];
                mat[j][n - 1 - i] = mat[n - 1 - i][n - 1 - j];
                mat[n - 1 - i][n - 1 - j] = mat[n - 1 - j][i];
                mat[n - 1 - j][i] = temp;
            }
        }
    }
};


int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16}
    };
    Solution sol;
    sol.rotateMatrix(matrix);

    for (const auto &row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}