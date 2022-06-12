class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        recurBottomUp(candidates, target, curr, res, 0);
        return res;
    }
    
    void recurBottomUp(vector<int> nums, int target, vector<int> &curr, vector<vector<int>> &res, int idx){
        if(idx == nums.size()){
            if(target == 0)
                res.push_back(curr);
            return;
        }
        if(target >= nums[idx]){
            curr.push_back(nums[idx]);
            recurBottomUp(nums,target-nums[idx],curr,res,idx);
            curr.pop_back();
        }
        recurBottomUp(nums,target,curr,res,idx+1);
    }
};