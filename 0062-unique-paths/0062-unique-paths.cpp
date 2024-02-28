class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
    for (int i = 0; i < m; i++) {
        vector<int> temp(n, 0); // Create a temporary vector to represent the current row.
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = temp[j - 1];
            temp[j] = up + left;
        }
         prev = temp; // Update the previous row with the values calculated for the current row.
    }
    return prev[n - 1];
    }
};