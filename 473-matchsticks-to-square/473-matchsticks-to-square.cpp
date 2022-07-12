class Solution {
public:
    bool makesquare(vector<int>& nums) {
        long sum = accumulate(nums.begin(), nums.end(), 0l), sideSum;
        if(sum % 4) return false;
        int n = nums.size(), all = (1<<n) - 1, sideLen = sum / 4;
        vector<int> sideCombinations, doubleSideCombinations(1<<n, false);
        for(int i = 0; i <= all; i++){
            sideSum = 0;
            for(int j = 0; j <= 15; j++)
                if(i>>j & 1) sideSum += nums[j];
            if(sideSum == sideLen){
                for(int k : sideCombinations){
                    if((k & i) == 0){
                        int t = k | i;
                        doubleSideCombinations[t] = true;
                        if(doubleSideCombinations[all ^ t]) return true;
                    }
                }
                sideCombinations.push_back(i);
            }
        }
        return false;
    }
};