class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // vector<int> dp(n+1, -1);
        // int ans = min(solve(cost,n-1, dp), solve(cost,n-2, dp));
        // return ans;
        
        for(int i=2;i<n;i++)
            cost[i] += min(cost[i-1],cost[i-2]);
        return min(cost[n-1],cost[n-2]);
    }

    int solve(vector<int>& cost, int index, vector<int>&dp){
        if(index<2) // base case
            return cost[index];
        if(dp[index]!=-1)
            return dp[index];
        return dp[index] = cost[index] + min(solve(cost, index-1, dp), solve(cost, index-2, dp));
    }
};