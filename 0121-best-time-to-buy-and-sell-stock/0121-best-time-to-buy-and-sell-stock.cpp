class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, lowestBoughtPrice = INT_MAX;
        for(int currPrice: prices){
            lowestBoughtPrice = min(currPrice, lowestBoughtPrice);
            int currProfit = currPrice - lowestBoughtPrice;
            maxProfit = max(currProfit, maxProfit);
        }
        return maxProfit;
        
    }
};