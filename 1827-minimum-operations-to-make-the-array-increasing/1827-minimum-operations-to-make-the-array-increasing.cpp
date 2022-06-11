class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minOp = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                minOp+=nums[i-1]-nums[i]+1;
                nums[i] = nums[i-1]+1;
            }
        }
        return minOp;
    }
};