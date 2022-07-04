class Solution {
public:
    
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> c(n, 1); // candies vector with default 1 to each student
        for (int i = 1; i < n; i++)
            if (r[i] > r[i - 1])
                c[i] = c[i - 1] + 1; // providing 1 extra candy to higher rating guy
        for (int i = n - 2; i>=0; i--)
            if (r[i] > r[i + 1]) 
                c[i] = max(c[i], c[i + 1] + 1); // if right 
        int res = 0;
        for (auto t: c) res += t; // adding up all candies
        return res;
    }
    
    int candy1(vector<int>& ratings) {
        if (!ratings.size()) 
            return 0;
            int ret = 1, up = 0, down = 0, peak = 0;
            for (int i = 1; i < ratings.size(); i++){
                if (ratings[i - 1] < ratings[i]){
                    peak = ++up;
                    down = 0;
                    ret += 1 + up;
                } else if (ratings[i - 1] == ratings[i])  {
                    peak = up = down = 0;
                    ret += 1;
                } else {
                    up = 0;
                    down++;
                    ret += 1 + down + (peak >= down ? -1 : 0);
                }
            }

            return ret;
    }
    
};