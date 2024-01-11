class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int right = 0, result = nums[0], sum = nums[0], n = nums.size();
    //     while(right++ < n - 1) {
    //         sum += nums[right];
    //         sum = max(nums[right], sum);
    //         result = max(result, sum);
    //     }
    //     return result;
    // }
    
    int maxCrossingSum(vector<int>& nums, int low, int mid, int high) {
        int leftSum = numeric_limits<int>::min();
        int sum = 0;

        for (int i = mid; i >= low; --i) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = numeric_limits<int>::min();
        sum = 0;

        for (int i = mid + 1; i <= high; ++i) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        return leftSum + rightSum;
    }

    int maxSubArrayHelper(vector<int>& nums, int low, int high) {
        if (low == high) {
            return nums[low];
        }
        int mid = (low + high) / 2;

        // Divide
        int leftMax = maxSubArrayHelper(nums, low, mid); // left subarray
        int rightMax = maxSubArrayHelper(nums, mid + 1, high); // right subarray
        int crossMax = maxCrossingSum(nums, low, mid, high);

        // Conquer
        return max({leftMax, rightMax, crossMax});
    }
    
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
};