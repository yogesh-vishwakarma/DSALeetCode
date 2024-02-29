class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rowLen = grid.size(), colLen = grid[0].size();
        vector<vector<int>> cache(rowLen+1, vector<int>(colLen+1, 0));
        for(int currRow = 1; currRow <= rowLen; currRow++){
            for(int currCol = 1; currCol <= colLen; currCol++){
                if(currCol == 1 && currRow == 1){
                    cache[currRow][currCol] = grid[currRow-1][currCol-1];
                }else if(currCol == 1 || currRow == 1){
                    cache[currRow][currCol] = grid[currRow-1][currCol-1] + cache[currRow-1][currCol] + cache[currRow][currCol-1];
                }else{
                    cache[currRow][currCol] = grid[currRow-1][currCol-1] + min(cache[currRow-1][currCol], cache[currRow][currCol-1]);
                }
            }
        }
        return cache[rowLen][colLen];
    }
};