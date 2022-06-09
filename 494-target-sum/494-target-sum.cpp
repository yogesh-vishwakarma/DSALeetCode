class Solution {
 public:
    /*------------backtracking
     int ans = 0;
     void helper(vector<int>& nums, int target, int index){
          if(index == nums.size()){
              if(target == 0) ans++;
              return;
          } else{
             helper(nums, target - nums[index], index+1);
             helper(nums, target + nums[index], index+1);
         }
     }
    
     int findTargetSumWays(vector<int>& nums, int target) {
         int sum = 0;
         helper(nums, target, 0);
         return ans;
     } */
    
    /*---------------memoization
    int total;
    
     int helper(vector<int>& nums, int target, vector<vector<int>>& dp, int sum, int index){
          if(index == nums.size()){
              if(target == sum) return 1;
              else return 0;
          } else{
             if(dp[index][sum+total] != INT_MIN) return dp[index][sum+total];
            
             int add = helper(nums, target, dp,  sum + nums[index], index+1);
             int sub = helper(nums, target, dp, sum - nums[index], index+1);
            
             dp[index][sum+total] = add + sub;
             return dp[index][sum+total];
         }
     }
    
     int findTargetSumWays(vector<int>& nums, int target) {
        
         total = accumulate(nums.begin(), nums.end(), 0);
         vector<vector<int>> dp(nums.size(), vector<int>(2*total +1, INT_MIN));
         return helper(nums, target, dp, 0, 0);
     } */
    
    /* 2D Tabulation
    int total;
    
     int findTargetSumWays(vector<int>& nums, int target) {
      
         total = accumulate(nums.begin(), nums.end(), 0);
         if(target > total || target<-total) return 0;
         vector<vector<int>> dp(nums.size(), vector<int>(2*total +1, 0));
        
         dp[0][nums[0]+total] = 1;
         dp[0][-nums[0]+total] += 1;
        
         for(int i = 1; i<nums.size(); i++){
             for(int sum = -total; sum <=total; sum++){
                 if (dp[i - 1][sum + total] > 0) {
                     dp[i][sum + nums[i] + total] += dp[i - 1][sum + total];
                     dp[i][sum - nums[i] + total] += dp[i - 1][sum + total];
                 }
             }
         }
         return dp[nums.size() - 1][target + total];
     }
    */
    // 1D DP
    int total;
    int findTargetSumWays(vector<int>& nums, int target) {
        
        total = accumulate(nums.begin(), nums.end(), 0);
        if(target > total || target<-total) return 0;
        vector<int> dp(2*total +1, 0);
        
        dp[nums[0]+total] = 1;
        dp[-nums[0]+total] += 1;
        
        for(int i = 1; i<nums.size(); i++){
            vector<int> next(2*total +1, 0);
            for(int sum = -total; sum <=total; sum++){
                if (dp[sum + total] > 0) {
                    next[sum + nums[i] + total] += dp[sum + total];
                    next[sum - nums[i] + total] += dp[sum + total];
                }
            }
            dp = next;
        }
        return dp[target + total];;
    }
 };