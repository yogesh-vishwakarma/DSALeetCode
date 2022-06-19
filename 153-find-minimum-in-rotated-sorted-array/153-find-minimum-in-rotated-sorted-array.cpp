class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;        
        while(l< r-1){
            int m = (l + r) / 2;
            if(nums[m] < nums[r]) 
                r = m;
            else
                l = m;            
        }
        return min(nums[l], nums[r]);        
    } 
};