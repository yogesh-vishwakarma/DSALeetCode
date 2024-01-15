class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        int prod = 1;
        for(int el: nums){
            prod *= el;
            result = max(result, prod);
            prod = prod == 0? 1: prod;
        }
        for(int i = nums.size() - 1, prod = 1; i >= 0; i--){
            prod *= nums[i];
            result = max(result, prod);
            prod = prod == 0? 1: prod;
        }
        return result;
    }
};