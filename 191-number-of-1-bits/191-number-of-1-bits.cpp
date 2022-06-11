class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res(0);
        while(n){
            n = (n & (n-1));
            // n  & (n-1) removes lowest setbit of n
            res++;
        }
        return res;
    }
};