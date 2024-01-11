class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int right = 0, result = nums[0], sum = nums[0], n = nums.size();
        while(right++ < n - 1) {
            sum += nums[right];
            sum = max(nums[right], sum);
            result = max(result, sum);
        }
        return result;
    }
};