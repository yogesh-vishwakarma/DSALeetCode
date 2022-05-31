class Solution {
public:
    int searchInsert(vector<int>&nums, int target){
        int left(0), right(nums.size()-1);
        while(left<=right){
            int mid = (left+right)/2;
            if(target == nums[mid])
                return mid;
            (nums[mid] < target)? left = mid+1:right=mid-1;
        }
        
        return left;
    }
};