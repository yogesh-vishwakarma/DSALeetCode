class Solution {
public:
    
    /* 
    
    numbers of permutations is: n!
    
    */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; // our dataset which will hold all results
        
        vector<int> curr; // intermediatory dataset to hold the indivisual ppermutation.
        // freq array to check if we have already used that index element
        int freq[nums.size()]; memset( freq, 0, sizeof(freq) ); // initializing all elements of the array to zero
        permuteBottomUP(nums,res,curr, freq);
        
        // permuteTopDown(0, nums, ans);
        return res;
    }
    
    void permuteBottomUP(vector<int> nums,vector<vector<int>> &res, vector<int> &curr,  int freq[] ){
        
        // base case
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }
        
        //bottom up for loop
        for(int i=0;i<nums.size();i++){
            
            if(!freq[i]){ //we check if the ith index is already visited or not
                curr.push_back(nums[i]); // we will take ith element in our permutation
                freq[i] = 1; // we will mark that element as already used
                permuteBottomUP(nums,res,curr,freq); // call the recursion 
                curr.pop_back(); // now we will pop that element
                freq[i] = 0;  // and also mark that element unused
            }
        }
        
    }
};