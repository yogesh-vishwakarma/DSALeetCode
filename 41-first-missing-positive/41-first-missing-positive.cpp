class Solution {
public:
    /* Cyclic Sort */
    int firstMissingPositive(vector<int>& nums) {
        int curr = 1, n = nums.size(); // take 2 pointers
        while( curr < n){
            if(nums[curr] > 0 && nums[curr] <= n && nums[curr] != nums[nums[curr] - 1]){
                swap(nums[curr],nums[nums[curr] - 1]);
            }else{
                curr++;
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return n + 1;
    }
};