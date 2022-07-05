class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset; int ans(0);
        
        for(int el : nums )
            uset.insert(el);
        
        for(auto el: nums ){
            if(uset.count(el-1)) 
                continue;
            // if we found prev means we already have checked for it so continue the loop
            int curr = el;
            int streak = 1;
            while(uset.count(curr+1)){
                ++curr;++streak;
            }
            ans = max(ans,streak);
        }
        return ans;
    }
    /*
    we can use 2 nested for loops
        or
    we can sort and use sliding window kind approach
        or
    Optimal Approach
    we need to compare single element with remaining elements or the array.
    se comapring takes o(n) normally couse of lookup which we can optimise upon using map/set.
    
    
    */
};