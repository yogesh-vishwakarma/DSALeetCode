class Solution {
public:
    
/*
Let's say nums looks like this: 
NUMS =  [12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

Because it's not fully sorted, we can't do normal binary search. But here comes the trick:

If target is let's say 14, then we adjust nums to this, where "inf" means infinity:
[12, 13, 14, 15, 16, 17, 18, 19, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf]

If target is let's say 7, then we adjust nums to this:
[-inf, -inf, -inf, -inf, -inf, -inf, -inf, -inf, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

And then we can simply do ordinary binary search.

We don't need to edit the actual array like that, we just need to make the comparator number(in regular case, the mid point that we select) to INF or -INF based on which side the target is and which side the mid point number is. the adjustment is done by comparing both the target and the actual element against nums[0].

 double num = (nums[mid] < nums[0]) == (target < nums[0]) -> checking if both target and nums[mid] are on same side.
                   ? nums[mid]                            -> they are in same side then mid is valid
                   // they aren't in same side then we are checking if out target/nums[mid]  is in first half or second
                   : target < nums[0]                     -> checking which half does the target exist in 
                       ? -INFINITY                        -> target is in second half and mid is in first so it should be -inf
                       : INFINITY;                        -> target is in first half then mid is in second half should be +inf
*/
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            double comparator = (nums[mid] < nums[0]) == (target < nums[0])
                       ? nums[mid]
                       : target < nums[0] ? -INFINITY : INFINITY;

            if (comparator < target)
                lo = mid + 1;
            else if (comparator > target)
                hi = mid;
            else
                return mid;
        }
        return -1;
    }
};