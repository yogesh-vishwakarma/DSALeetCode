class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, lowestPrice = INT_MAX;
        for (int el : prices) {
            lowestPrice = min(lowestPrice, el);
            maxProfit = max(maxProfit, el - lowestPrice);
        }
        return maxProfit;
    }
};