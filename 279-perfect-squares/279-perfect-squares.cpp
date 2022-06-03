class Solution {
public:
    
        int solve(int n, vector<int>&dp){
        if(n==0 || n==1)
            return n;
        
        if(dp[n]!=-1)  
            return dp[n];
        
        int mini = INT_MAX;
        for(int i=1;i<=sqrt(n);i++){
            if(n - pow(i, 2) >=0)
                mini = min(mini, solve(n-pow(i, 2), dp) + 1);
        }
        dp[n] = mini;
        return mini;
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
    
    /*IThen we can convert the top-down solution to the bottom-up solution.
    By knowing which subproblem is dependent on which subproblem, we can then decide the traverse direction of the dp table. 
    Larger numbers' results are dependent on smaller numbers, so smaller numbers should be solved first. */
    int numSquares2(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0; dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1; ; j++){
                if(i-j*j<0) break;
                dp[i]=min(dp[i] , dp[i-j*j]+1 );
            }
        }
        return dp[n]; 
    }
};