class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int localMax(0), totalMax(INT_MIN);
        for(int i=0; i<n;i++){
            localMax = max(nums[i]+localMax, nums[i]);
            totalMax = max(totalMax,localMax);
        }
        return totalMax;
    }
};