class Solution {
public:
    int dp[12 + 1][10000 + 1];
    
    int coinChange(vector<int>& coins, int amount) {
        // int res = findLowestCoins(coins, 0, amount);
        int res = findLowestCoinsDP(coins, coins.size(), amount);
        return (res == INT_MAX - 1 ) ? -1 : res;
    }

    
    int findLowestCoinsDP(vector<int> &coins, int arraySize, int amount) {
        for (int i = 0; i < arraySize + 1; i++)
            for (int j = 0; j < amount + 1; j++){
                if (i == 0 || j == 0)
                    dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;
                if ( i>0 && j>0 && coins[i - 1] > j)
                    dp[i][j] = 0 + dp[i - 1][j];
                else if( i>0 && j>0)
                    dp[i][j] = min(0 + dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            
            }        
        return dp[arraySize][amount];
    }    

    int findLowestCoins(vector<int> &coins, int cur, int amount) {
        if (cur >= coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;   
        
        int res = -1;
        if (coins[cur] > amount) {
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            res = doNotTakeCoin;
        }
        else {
            int takeCoin = 1 + findLowestCoins(coins, cur + 0, amount - coins[cur]);
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            res = min(takeCoin, doNotTakeCoin);
        }
        return res;
    }
    

};