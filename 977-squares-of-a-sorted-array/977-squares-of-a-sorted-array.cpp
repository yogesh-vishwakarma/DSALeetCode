class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        transform(nums.begin(), nums.end(),nums.begin(),[](int i){return abs(i * i);});
        sort(nums.begin(),nums.end());
        return nums;
    }
};