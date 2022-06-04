class Solution {
public:
    void recursionTopDown(vector<vector<int>> &P,vector<int> nums,int idx){
        if(idx==nums.size()){
            P.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            recursionTopDown(P,nums,idx+1);
            // swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        recursionTopDown(res,nums,0);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};