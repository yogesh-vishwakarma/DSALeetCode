class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int mid;

        while(i<=j){
            mid = i +(j-i)/2;

            if(nums[mid]==original){
                i = mid + 1;
                j = nums.size()-1;
                original *= 2;
            }
            else if(nums[mid]<original)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return original;
    }
};