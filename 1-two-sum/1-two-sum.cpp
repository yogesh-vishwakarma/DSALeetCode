class Solution {
    // here an unoreddered map is used to store th detaila and pop it back again.
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> mp;
        for(int i=0; i<n;i++){
            if(mp.find(target - nums[i]) != mp.end()){
                result.push_back(mp[target-nums[i]]);
                result.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return result;     
    }
};