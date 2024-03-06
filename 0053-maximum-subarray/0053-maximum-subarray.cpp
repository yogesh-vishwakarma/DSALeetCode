class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum = INT_MIN, currSum = 0;
        for(int el: nums){
            // currSum = max(el, currSum+el);
            currSum += el;
            largestSum = max(largestSum, currSum);
            currSum = currSum < 0? 0: currSum;
        }
        return largestSum;
    }
};