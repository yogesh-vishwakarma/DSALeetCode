class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, currLowestPrice = INT_MAX;
        for (int el : prices) {
            currLowestPrice = min(currLowestPrice, el);
            int currentProfit = el - currLowestPrice;
            maxProfit = max(maxProfit, currentProfit);
        }
        return maxProfit;
    }
};