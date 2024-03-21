class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int currRow = matrix.size() - 1, currCol = matrix[0].size() - 1;
        while (currRow >= 0 && currCol >= 0) {
            if (matrix[currRow][currCol] == target) {
                return true;
            } else if (currRow - 1 >= 0 &&
                       matrix[currRow - 1][currCol] >= target) {
                currRow--;
            } else {
                currCol--;
            }
        }
        return false;
    }
};