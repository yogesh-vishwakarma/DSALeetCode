class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnter =0;
        int maxi=0;

        for( int i=0;i<nums.size();i++){
            if(nums[i] == 1){ cnter++;}
            else{
                maxi = max(maxi, cnter);
                cnter =0;
            }
        }
        maxi = max(maxi, cnter);
        return maxi;
        
    }
};