class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        
        recur(nums, res, curr, 0);
        
        return res;
        
    }
    
    void recur(vector<int> nums, vector<vector<int>> &res, vector<int> &curr, int idx){
        
        res.push_back(curr);
        
        for(int i = idx; i< nums.size();i++){
            if( i!=idx && nums[i] == nums[i-1])
                continue;
            curr.push_back(nums[i]);
            recur(nums,res,curr,i+1);
            curr.pop_back();
            
        }
    }
    
};