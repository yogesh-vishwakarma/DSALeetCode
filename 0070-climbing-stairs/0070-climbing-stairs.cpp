class Solution {
public:
    int climbStairs(int n) {
        int lastWayCount = 1, ans = 1;
        for(int i = 2; i<= n;i++){
            ans = lastWayCount + ans;
            lastWayCount = ans - lastWayCount;
        }
        return ans;
    }
};