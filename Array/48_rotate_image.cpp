#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();     // total rows
        int m = matrix[0].size();  // total columns

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(matrix);
    for (auto &vectors : matrix) {
        for (auto &ele : vectors) {
            cout << ele << " ";
        }
        cout << endl;
    }
}