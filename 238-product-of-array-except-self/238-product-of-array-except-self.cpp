class Solution {
public:
    vector<int> productExceptSelf(vector<int> nums) {
        // vector<int> output(nums.size(),1);
        // for (int i = 1; i < nums.size(); ++i){
        //     output[i] = output[i-1] * nums[i-1];
        // }
        // for (int i = nums.size() - 2; i >= 0; --i){
        //     nums[i] *= nums[i + 1];
        //     output[i] *= nums[i+1];
        // }
        // return output;
        
        /* Method 2 */
        int mul = 1, zeroCnt(0);
        for(auto el: nums){
            if(el == 0)
                zeroCnt++;
            else
                mul *=el;
        }
        for(int i = 0;i<nums.size();i++){
            if(zeroCnt){
                if(nums[i]==0 && zeroCnt>1)
                    nums[i] = 0;
                else if(nums[i]==0)
                    nums[i] = mul;
                else
                    nums[i] = 0;
            }else{
                nums[i] = mul/nums[i];
            }
        }
        return nums;
        
    }
};