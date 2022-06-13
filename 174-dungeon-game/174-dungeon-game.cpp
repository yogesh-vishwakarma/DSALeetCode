class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon){
        
         int m = dungeon.size(), n = dungeon[0].size(), i, j;
        vector<vector<int>> dp(m+1, vector<int>(n+1,INT_MAX));

        dp[m][n-1] = 1;dp[m-1][n] = 1;

        for(i=m-1; i>=0; i--){
            for(j=n-1; j>= 0; j--){
                int min_power = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = min_power <= 0? 1: min_power;
            }
        }
        return dp[0][0];
    }
};