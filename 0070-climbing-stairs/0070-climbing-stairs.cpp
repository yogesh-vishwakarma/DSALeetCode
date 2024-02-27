class Solution {
public:
    int climbStairs(int n) {
        int lastWayCount = 1, ans = 1;
        for(int i = 2; i<= n;i++){
            ans = lastWayCount + ans;
            lastWayCount = ans - lastWayCount;// to get old ans val as it's modified in above line
        }
        return ans;
    }
};