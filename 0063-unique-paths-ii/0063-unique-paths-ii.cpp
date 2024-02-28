class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<int> dp(cols, 0);
        dp[0] = !obstacleGrid[0][0];
        for(int i = 1; i < cols; i++) {
            if(obstacleGrid[0][i]) 
                break;
            dp[i] += (dp[i-1]);
        }
        for(int i = 1; i < rows; i++) {
            for(int j = 0; j < cols; j++ ) {
                if(!obstacleGrid[i][j]) {
                    if( j != 0 )
                        dp[j] += dp[j - 1]; 
                } else dp[j] = 0;
            }
        }
        return dp[cols - 1];
    }
};