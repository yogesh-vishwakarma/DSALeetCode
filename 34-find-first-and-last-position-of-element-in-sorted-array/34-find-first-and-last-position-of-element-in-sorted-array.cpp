class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
        /* using STL
        vector::iterator it1 = lower_bound(nums.begin(), nums.end(), target);
        vector::iterator it2 = upper_bound(nums.begin(), nums.end(), target);

        if(it1 < it2 ) return {int(it1 - nums.begin()),int(--it2 - nums.begin())};
        return {-1,-1};
        */
        
        int n = nums.size();
        int s=0, e=n-1;
        int start = -1;
        int end = -1;
        
        //For First Occurence(i.e. Lower_Bound)
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == target){
                start = mid;
                e = mid-1;
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
            if(nums[mid] == target)
            {
                end = mid;
                s = mid+1;
            }
            else if(nums[mid] > target)
                e = mid-1;
            else
                s = mid+1;
        }
        return {start,end};  
    }
};