#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC - O(rows × cols) NEARLY O(n*n)
    // SC - O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1;  // flag for first column

        // Step 1: Mark the first row and first column
        // If a cell is zero, mark its row's first cell and col's first cell as zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;  // mark row
                    if (j == 0)
                        col0 = 0;  // special case: first column
                    else
                        matrix[0][j] = 0;  // mark column
                }
            }
        }

        // Step 2: Zero out cells based on markers (skip first row & col for now)
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle the first row separately
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle the first column separately
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }

    // TC - O(rows × cols) NEARLY O(n*n)
    // SC - O(rows + cols) We can saythat O(m+n)
   public:
    void setZeroesBetter(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Arrays to remember which rows and columns need to be zeroed
        vector<int> markRow(rows, 0);
        vector<int> markCol(cols, 0);

        // Step 1: Identify rows and cols that contain at least one zero
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    markRow[i] = 1;
                    markCol[j] = 1;
                }
            }
        }

        // Step 2: Update the matrix based on marked rows and cols
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (markRow[i] == 1 || markCol[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
