class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
/*
Here we are choosing min value 

*/
            // double num = (nums[mid] < nums[lo]) == (target < nums[lo]) ?
            //             nums[mid] : 
            //             (target < nums[lo] ? -INFINITY : INFINITY);
            
            double num;
            if(nums[mid] < nums[lo] == target < nums[lo])
                num = nums[mid];
            else{
                if(target < nums[lo])
                    num = -INFINITY;
                else
                    num = INFINITY;
            }

            if (num < target)
                lo = mid + 1;
            else if (num > target)
                hi = mid;
            else
                return mid;
        }
        return -1;
    }
};