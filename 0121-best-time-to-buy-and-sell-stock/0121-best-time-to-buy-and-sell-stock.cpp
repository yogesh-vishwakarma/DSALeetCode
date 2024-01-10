class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, maxVal = 0;
        for(int i = prices.size() -1; i >=0 ; i--){
            maxVal = max(maxVal, prices[i]);
            result = max(result, (maxVal - prices[i]));
        }
        return result;
    }
};