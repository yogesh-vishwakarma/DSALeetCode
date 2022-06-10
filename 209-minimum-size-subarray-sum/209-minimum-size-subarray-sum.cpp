class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans =INT_MAX;
            long long sum=0;
            int i=0,j=0;
            
            while(j<nums.size()){
                    sum+=nums[j];
                    
                    if(sum>=target){
                            ans=min(ans,j-i+1);
                            
                            while(sum>=target){
                                    sum-=nums[i];
                                    i++;
                            }
                            ans=min(ans,j-i+2);
                            
                    }
                    j++;
                    
            }
            if(ans==INT_MAX)
                return 0;
            return ans;  
    }
};