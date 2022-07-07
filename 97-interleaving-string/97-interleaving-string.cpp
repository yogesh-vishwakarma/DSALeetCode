class Solution {
public:
    /*
    BFS Approach: https://leetcode.com/problems/interleaving-string/discuss/31948/8ms-C%2B%2B-solution-using-BFS-with-explanation
    DFS Approach: https://leetcode.com/problems/interleaving-string/discuss/31888/1ms-tiny-DFS-beats-94.57
    */
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), p = s3.size();

        if (m + n != p) 
            return false;

        vector<bool> dp(n + 1);//initialize
        
        for (int j = 0; j <= n; j++)  
            dp[j] = s2.substr(0, j)==s3.substr(0, j); 
        // here we are checking if s2 & s3 have common prefix and what is the length.   
        
        for (int i = 1; i <= m; i++){
            dp[0] = s1.substr(0, i)==s3.substr(0, i);
            // here we are checking if s1 & s3 have common prefix and what is the length & storing at 0th index. 
            for (int j = 1; j <= n; j++)
                dp[j] = (dp[j] && s3[i+j-1]==s1[i-1]) || (dp[j-1] && s3[i+j-1]==s2[j-1]);
            
        }
        
        for(auto el:dp) cout <<el<<" ";cout << endl;

        return dp[n];

    }
    /*
    Here In current Approach:
        we are creating a 2d array when hotizontal bars are string 1 & vertical path is string 2 
        so basically our string 3 is a path on that matrix
        see BFS approach for clearity.
    */
};