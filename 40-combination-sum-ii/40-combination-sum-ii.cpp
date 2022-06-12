class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        recurBottomUp(candidates, target, curr, res, 0);
        return res;
        
    }
    void recurBottomUp(vector<int> arr, int target, vector<int> &curr, vector<vector<int>> &res, int idx){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        for(int i=idx; i<arr.size(); i++){
            
            // here we slip over duplicates
            if(i>idx && arr[i] == arr[i-1])
                continue;
            if(arr[i]<=target){
                curr.push_back(arr[i]);
                recurBottomUp(arr,target - arr[i],curr,res,i+1);
                curr.pop_back();
            }
        }
    }
    
    // void recurBottomUp(vector<int> nums, int target, vector<int> &curr, vector<vector<int>> &res, int idx){
    //     if(idx == nums.size()){
    //         if(target == 0)
    //             res.push_back(curr);
    //         return;
    //     }
    //     if(target >= nums[idx]){
    //         curr.push_back(nums[idx]);
    //         recurBottomUp(nums,target-nums[idx],curr,res,idx+1);
    //         curr.pop_back();
    //     }
    //     recurBottomUp(nums,target,curr,res,idx+1);
    // }
    
    
};