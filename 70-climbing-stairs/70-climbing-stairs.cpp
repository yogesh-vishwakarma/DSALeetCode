class Solution {
public:
    // recursion
    int climbStairsR(int n) {
        if(n < 3)
            return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
    // memoization
    int climbStairsM(int n){
        vector<int> mem(n+1,-1);
        return memoizationHelper(n,mem);
    }
    
    int memoizationHelper(int n, vector<int> &mem) {
        if(n < 3)
            return n;
        if(mem[n]!=-1)
            return mem[n];
        return mem[n] = memoizationHelper(n-1, mem) + memoizationHelper(n-2, mem);
    }
    // tabulation
    int climbStairsT(int n){
        vector<int> tab(n+1,-1);
        tab[0]=1;tab[1]=2;
        for(int i(2);i<n;i++){
            tab[i] = tab[i-1] + tab[i-2];
        }
        return tab[n-1];
    }

    // space optimisation
    int climbStairs(int n){
        int prev2 = 1, prev = 1;
      for(int i=2; i<=n; i++){
          int cur_i = prev2+ prev;
          prev2 = prev;
          prev= cur_i;
      }
        return prev;
    }
};