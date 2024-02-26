class Solution {
public:
    bool check(vector<int>& nums) {
        int breakPoints = 0, n=nums.size();
        for(int i=0; i < n; i++){
            if(nums[i] > nums[(i+1)%n]){
                breakPoints++;
            }
        }
        return breakPoints <= 1 ? true : false;
    }
};