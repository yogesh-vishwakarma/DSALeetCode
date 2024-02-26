class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    // {
    //     int i = 0, n=nums.size();
    //     for (int j = 1; j < n; j++) {
    //         if (nums[i] != nums[j]) {
    //         i++;
    //         nums[i] = nums[j];
    //         }
    //     }
    //     return i + 1;
    // }
    {
        int k = 0,n = nums.size();
        for(int i=0;i<n;i++){
            int j = i;
            while(j<n and nums[i]==nums[j]){
                j++;
            }
            nums[k++] = nums[i];
            i = j -1;
        }
        return k;
    }
};