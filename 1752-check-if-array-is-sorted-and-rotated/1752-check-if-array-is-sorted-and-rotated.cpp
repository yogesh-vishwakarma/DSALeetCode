class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            cnt += nums[i] > (nums[(i + 1) % n]);
        }
        return cnt <= 1;
    }
    // bool check(vector<int>& nums) {
    //     int breakPoints = 0, n=nums.size();
    //     for(int i=0; i < n; i++){
    //         if(nums[i] > nums[(i+1)%n]){
    //             breakPoints++;
    //         }
    //     }
    //     return breakPoints <= 1 ? true : false;
    // }
};