class Solution {
public:
/*
Method 1: 3 for loops

Method 2: Hashing
        hashmap <pair, occurence>

Optimal: 
        Sort, then 2 pointer
*/
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size(), targetSum = 0;
        int a, b, c; // nums[a]+nums[b]+nums[c] = 0
        
        for(a=0 ; a < n-2; a++){ // n-2, n-1 elements should be b and c
            if(a==0 || (a>0 && nums[a]!=nums[a-1]) ){ // to avoid duplicates
                b = a+1, c = n-1;
                int sum = targetSum - nums[a]; //to check nums[b] + nums[c] = sum;
                while(b<c){
                    if(nums[b] + nums[c] == sum){
                        res.push_back({nums[a],nums[b],nums[c]});
                        
                        while(b<c && nums[b] == nums[b+1]) b++; // for ignoring duplicates
                        while(b<c && nums[c] == nums[c-1]) c--; // ignoring duplicate elements
                        
                        b++;c--;
                    }else if(nums[b] + nums[c] < sum)
                        b++;
                    else
                        c--;

                }
            }
        }
        
        return res;
    }
};