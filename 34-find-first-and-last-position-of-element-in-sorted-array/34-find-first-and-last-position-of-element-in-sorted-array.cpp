class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
        /* using STL
        vector::iterator it1 = lower_bound(nums.begin(), nums.end(), target);
        vector::iterator it2 = upper_bound(nums.begin(), nums.end(), target);

        if(it1 < it2 ) return {int(it1 - nums.begin()),int(--it2 - nums.begin())};
        return {-1,-1};
        */
        
        int n = nums.size(), s=0, e=n-1;
        int res1 = -1, res2 = -1;
        
        //For First Occurence(i.e. Lower_Bound)
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == target){
                res1 = mid;
                e = mid-1; // diffrence
            }
            else if(nums[mid] > target)
                e = mid-1;
            else
                s = mid+1;
        }
        //For Last Occurence(i.e. Upper_Bound)
        s = 0, e = n-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == target){
                res2 = mid;
                s = mid+1; // diffrence
            }
            else if(nums[mid] > target)
                e = mid-1;
            else
                s = mid+1;
        }
        return {res1,res2};  
    }
};