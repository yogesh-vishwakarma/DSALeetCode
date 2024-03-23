class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long gridSum = 0, gridSqSum = 0;
        for (auto row : grid) {
            for (int el : row) {
                gridSum += el;
                gridSqSum += el * el;
            }
        }
        int n = grid.size() * grid.size();
        long long nSum = n * (n + 1) / 2;
        long long nSqSum = n * (n + 1) * (2 * n + 1) / 6;
        vector<int> result;
        int duplicateEl =
            (((gridSqSum - nSqSum) / (gridSum - nSum)) + gridSum - nSum) / 2;
        int missingEl = gridSum - nSum - duplicateEl;
        result.push_back((duplicateEl));
        result.push_back(abs(missingEl));
        return result;
    }
};