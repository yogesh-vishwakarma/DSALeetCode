class Solution {
public:
    vector<int> productExceptSelf(vector<int> nums) {
        int arrLen = nums.size();
        vector<int> result(arrLen, 1);
        for(int i = 1; i < arrLen; i++){
            result[i] = result[i-1] * nums[i-1];
        }
        int rightSubArrProduct = 1;
        for(int i = arrLen - 1; i >= 0; i--){
            result[i] *= rightSubArrProduct;
            rightSubArrProduct *= nums[i];
        }
        return result;
    }
};