class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum(0), res, n(nums.size());
        for(auto i : nums)
            sum +=i;
        res = (n*(n+1)/2) - sum;
        return res;
    }
    /*  Cyclic Sort */
    int missingNumber1(vector<int>& nums) {
      int start=0; int n = nums.size();
        
        while(start<n){
            if(nums[start]<n && start!=nums[start]) // checking if no is present on index or not
                swap(nums[nums[start]], nums[start]);
            else
                start++;         
        }
       for(int i=0;i<n;i++)
           if(nums[i]!=i)
               return i;
        return 
            n;
    }
};