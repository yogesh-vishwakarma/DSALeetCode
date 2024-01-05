class Solution {
public:
    void sortColors(vector<int>& nums){
        int zeroEndPtr = 0, twoStartPtr = nums.size() - 1, curr = 0;
        while(curr <= twoStartPtr){
             if(nums[curr] == 0){
                swap(nums[zeroEndPtr++], nums[curr++]);
            }else if(nums[curr] == 2){
                swap(nums[curr], nums[twoStartPtr--]);
            }else{
                 curr++;
            }
        }
    }
};