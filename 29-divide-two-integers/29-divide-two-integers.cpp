class Solution {
public:
    int divide(int da, int di) {
        if(da == INT_MIN && di == -1)
            return INT_MAX;
        
        long div = labs(da),dd = labs(di);
        long long s = 1;
        if(da < 0 && di > 0 || da > 0 && di < 0)s = -1;
        
        int ans = 0;
        while(div >= dd){
            long temp = dd,m = 1;
            while(temp << 1 <= div){
                temp <<= 1;
                m <<= 1;
            }
            div -= temp;
            ans += m;
        }
        return ans*s;
    }
};