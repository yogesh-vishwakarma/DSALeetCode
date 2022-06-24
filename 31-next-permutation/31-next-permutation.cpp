class Solution {
public:
    /*
    generate all and choose next one.
    
    next permutation is min no which is greater than current using same elements.
    123 -> 132
    321 -> 123 (321 is biggest so we reset the permutation)
    13542-> 14235
    optimal: 
        traverse from back and find local maxima. (5)
        find smallest no greater than 3(one index prev of local max) -> 4.
        swap then -> 14532
        now to make it smallest possible sort after swapped index(4)-> 14235 (ans)
        
    
    */
    void nextPermutation_STL(vector<int> &arr) {
        auto left = is_sorted_until(rbegin(arr), rend(arr));
        if (left != rend(arr)) {
          auto right = upper_bound(rbegin(arr), left, *left);
          iter_swap(left, right);
        }
        reverse(left.base(), end(arr));
    }
    
    void nextPermutation(vector<int>& nums) {    
        int n = nums.size(), localMax = n-2;
        
        while(localMax>=0 && nums[localMax] >= nums[localMax+1]) 
            localMax--;
        // localMax++;
        cout << localMax<<endl;
        if(localMax<0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int i;
        for(i = n-1;i>localMax;i--){
            if(nums[i]>nums[localMax])
                break;
        }
        swap(nums[localMax],nums[i]);
        
        reverse(nums.begin()+localMax+1,nums.end());
    }
};