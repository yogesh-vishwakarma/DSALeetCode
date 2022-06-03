class Solution {
public:
    /*
    https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
    So it boils down to calculating what is more profitable:
        robbery of current house + loot from houses before the previous
        loot from the previous house robbery and any loot captured before that
    
    rob(i) = max( rob(i - 2) + currentHouseValue, rob(i - 1) );
    
    // recursive approach
    
    int rob(int[] nums, int i) {
        if (i < 0)
            return 0;
        return max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    }
    
    int rob(int* nums) {
        return rob(nums, nums.length - 1);
    }
    
    We can either start from house 1 or house 2 
    Incase of nums = [1,2,3,1]
    
    dp[0] = 1 and dp[1] = 2 (The dp[1] state contains the maximum of the robbery that can be made)
    
    Now will the remaining dp states using max(dp[i-1],dp[i-2] + nums[i])
    Which means that we are trying out the two possibilities to get the maximum from the previous house (1 index behind) and previous house (2 index    behind ) + current house.
    
    In the end we are returning the last dp state which stores our maximum value
    */
    int robMod(vector<int>& nums) {
        if (nums.size() == 0) 
            return 0;
        int prev1 = 0;
        int prev2 = 0;
        for (int num : nums) {
            int tmp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = tmp;
        }
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int first=nums[0];
        int second=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int prev_first=first; //storing prev i-2th value
            first=second;
            second=max(nums[i]+prev_first,second);
        }
       return second; 
    }
};