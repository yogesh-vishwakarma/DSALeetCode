class Solution {
public:
    int minPartitions(string n) {
        int ans(0);
        for(auto itr: n)
            ans= max(ans,(itr-'0') );
        return ans;
    }
};