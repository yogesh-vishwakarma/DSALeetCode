class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        // findCombTopDown(candidates, target, ans, temp, 0);
        findCombBottomUp(candidates, target, 0, temp, ans);
        return ans;
    }
    
    /* top down approach */
    void findCombTopDown(vector<int> &nums, int target, 
                         vector<vector<int>> &ans, vector<int> curr, int ind){
        // base case
        if(ind == nums.size()){
            /* if our curr vector satisfy the sum add it to ans
            here we are modifying the target value, instead of that 
            we could have added sum of all elements of curr vector */
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }
        
        // pick element
        if(nums[ind] <=  target){
            curr.push_back(nums[ind]);
            
            // now run rec of when we choose the element nums[ind]
            findCombTopDown(nums,target-nums[ind],ans,curr,ind);
            
            //now we will pop the nums[ind] to create rec for scenario where we won't pich the element.
            curr.pop_back();
        }
        // now we will create rec for scenario of ignoring the curr index and move further
        findCombTopDown(nums,target,ans,curr,ind+1);
    }
    
    
    /* bottom up approach */
    
    void findCombBottomUp(vector<int> &cd, int target, 
                        int start, vector<int> output, vector<vector<int>> &result){
        if(target == 0){
            result.push_back(output);
            return;
        }
        
        for(int i = start; i < cd.size(); i++){
            int val = cd[i];
            if(target >= val){
                output.push_back(val);
                findCombBottomUp(cd, target - val,i, output, result);
                output.pop_back();
            } else {
                break;
            }
        }
    }
};