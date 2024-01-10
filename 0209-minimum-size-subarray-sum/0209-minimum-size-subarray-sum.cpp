class Solution {
public:
   int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), result = INT_MAX;
        int left = 0, right = 0, sum = 0;

        while (right < n) {
            sum += nums[right];

            while (sum >= target) {
                result = min(result, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        return result == INT_MAX ? 0 : result;
    }
};