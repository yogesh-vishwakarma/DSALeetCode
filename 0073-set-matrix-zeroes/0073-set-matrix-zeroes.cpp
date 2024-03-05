class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowCount = matrix.size(), colCount = matrix[0].size();
        bool ifFirstRowZero = false;
        for (int currRow = 0; currRow < rowCount; currRow++) {
            for (int currCol = 0; currCol < colCount; currCol++) {
                if (matrix[currRow][currCol] == 0) {
                    if (currRow == 0) {
                        ifFirstRowZero = true;
                    } else {
                        matrix[0][currCol] = 0;
                        matrix[currRow][0] = 0;
                    }
                }
            }
        }

        for (int currRow = 1; currRow < rowCount; currRow++) {
            for (int currCol = 1; currCol < colCount; currCol++) {
                matrix[currRow][currCol] =
                    !matrix[0][currCol] || !matrix[currRow][0]
                        ? 0
                        : matrix[currRow][currCol];
            }
        }

        if (matrix[0][0] == 0) { // matrix[0][0] is for first Column zero
            for (int j = 0; j < rowCount; j++) {
                matrix[j][0] = 0;
            }
        }
        if (ifFirstRowZero) {
            for (int i = 0; i < colCount; i++) {
                matrix[0][i] = 0;
            }
        }
        return;
    }
};