class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int totalWater = 0;
        int maxLeftKnownHeight = 0, maxRightKnownHeight = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeftKnownHeight) {
                    maxLeftKnownHeight = height[left];
                } else {
                    totalWater += maxLeftKnownHeight - height[left];
                }
                left++;
            } else {
                if (height[right] >= maxRightKnownHeight) {
                    maxRightKnownHeight = height[right];
                } else {
                    totalWater += maxRightKnownHeight - height[right];
                }
                right--;
            }
        }
        return totalWater;
    }
};