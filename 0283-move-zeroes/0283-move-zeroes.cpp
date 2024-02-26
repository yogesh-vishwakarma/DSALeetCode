class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        while(p2 < nums.size()){
            if(nums[p2] == 0) p2++;
            else{
                swap(nums[p1++], nums[p2++]);
            }
        }
    }
};