class Solution {
public:
    // bool check(vector<int>& nums) {
    //     int cnt = 0;
    //     for (int i = 0, n = nums.size(); i < n; ++i) {
    //         cnt += nums[i] > (nums[(i + 1) % n]);
    //     }
    //     return cnt <= 1;
    // }
    bool check(vector<int>& nums) {
        int breakPoints = 0, n=nums.size();
        for(int i=1; i < n ; i++){
            if(nums[i-1] > nums[i]){
                breakPoints++;
            }
        }
        if(nums[n-1]>nums[0]){
            breakPoints++;
        }
        return breakPoints <= 1 ? true : false;
    }
};