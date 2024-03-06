class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum = INT_MIN, currSum = 0;
        for(int el: nums){
            currSum = max(el, currSum+el);
            largestSum = max(largestSum, currSum);
        }
        return largestSum;
    }
};