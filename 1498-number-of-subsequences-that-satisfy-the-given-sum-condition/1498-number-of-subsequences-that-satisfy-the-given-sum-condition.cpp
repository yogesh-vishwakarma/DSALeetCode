class Solution {
public:
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size()-1;
        int ans = 0;
        long long por[nums.size()+1];
        por[0]=1;

        /// Also, we can reduce the no.calculations for calculating power as well (I just didn't do it here)
        for (int i=1; i<=nums.size(); i++) {
            por[i] = (2*por[i-1])%1000000007;
        }
        while(l<=r) {
            int sum = nums[l]+nums[r];
            if (sum<=target) {
                ans = ((ans + por[r-l])%1000000007);
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};