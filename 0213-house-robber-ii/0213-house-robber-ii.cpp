class Solution {
public:
    int rob(vector<int>& nums) {
        int n =  nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> nums1, nums2;
        for(int i=0; i<n;i++){
            if(i!= n-1) nums1.push_back(nums[i]);
            if(i != 0 ) nums2.push_back(nums[i]);
        }
        return max( robMaxAmount(nums1), robMaxAmount(nums2) );
    }

    int robMaxAmount(vector<int> nums){
        int arrLen = nums.size();
        if(arrLen == 1){
            return nums[0];
        }
        vector<int> cache(arrLen+1, -1);
        cache[0] = nums[0]; cache[1] = max(nums[0], nums[1]);
        for(int idx = 2; idx < arrLen; idx++){
            int includeCurr = cache[idx-2] + nums[idx];
            int excludeCurr = cache[idx-1];
            cache[idx] = max(includeCurr, excludeCurr);
        }
        return cache[arrLen-1];
    }
};