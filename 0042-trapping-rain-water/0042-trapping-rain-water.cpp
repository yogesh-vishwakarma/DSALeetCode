class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMaxHeight(n), rightMaxHeight(n);
        leftMaxHeight[0] = height[0];
        rightMaxHeight[n-1] = height[n-1];

        for (int i = 1; i < n; i++) {
            leftMaxHeight[i] = max(leftMaxHeight[i - 1], height[i]);
        }
        for (int i = n-2; i >=0; i--) {
            rightMaxHeight[i] = max(rightMaxHeight[i + 1], height[i]);
        }

        int totalWaterTrapped = 0;
        for (int i = 0; i < n; i++) {
            totalWaterTrapped += min(leftMaxHeight[i], rightMaxHeight[i]) -height[i];
        }
        return totalWaterTrapped;
    }
};