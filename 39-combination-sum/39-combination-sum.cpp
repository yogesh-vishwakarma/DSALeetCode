class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        bottomUpRec(candidates,target,temp,ans,0);
        return ans;
    }
    
    void bottomUpRec(vector<int> nums, int target, vector<int> &curr, vector<vector<int>> &res, int idx){
        if(idx == nums.size()){
            if(target == 0)
                res.push_back(curr);
            return;
        }
        if(target >= nums[idx]){
            curr.push_back(nums[idx]);
            bottomUpRec(nums,target-nums[idx],curr,res,idx);
            curr.pop_back();
        }
        bottomUpRec(nums,target,curr,res,idx+1);
    }
};