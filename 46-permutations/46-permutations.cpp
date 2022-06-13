class Solution {
public:
    
bool METHOD1 = false; 
        
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        if(METHOD1){
            vector<int> curr;
            int freq[nums.size()];memset( freq, 0, sizeof(freq) ); // initialized to zero
            recBottomUp(nums,res,curr,freq);
        }else{
            recMethod2(nums, res, 0);
        }
        
        return res;
    }
    
    void recBottomUp( vector<int> nums, vector<vector<int>> &res, vector<int> &curr, int *freq){
        //base case
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return;
        }
        /*
        we created recursion of all the elements of nums.
        we use freq array to check if that element is already used in permutation or not.
        */
        for(int i=0;i<nums.size();i++){
            if(freq[i])
                continue;
            curr.push_back(nums[i]);
            freq[i] = 1;
            recBottomUp(nums, res, curr, freq);
            freq[i] = 0;
            curr.pop_back();
        }
    }
    
    void recMethod2(vector<int> nums, vector<vector<int>> &res, int index){
        // base case
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }
        /*
        Using swap method, we can generate all possible combinations.
        here the index pointer works in simillar way to freq array in prev meathod.
        */
        for(int i(index);i<nums.size();i++){
            swap(nums[index], nums[i]);
            recMethod2(nums,res,index+1);
            swap(nums[index], nums[i]);
        }
    }
};