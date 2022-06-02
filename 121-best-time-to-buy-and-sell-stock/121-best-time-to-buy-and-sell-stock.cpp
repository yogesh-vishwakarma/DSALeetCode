class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res(0), mx(0);
        for(int i = prices.size()-1;i>=0;i--){
            mx =  max(mx,prices[i]); 
            res  = max(res, mx-prices[i]);
        }
        return res;
    }
};