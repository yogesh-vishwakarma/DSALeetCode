class Solution {
public:
    /*
    BFS Approach: https://leetcode.com/problems/interleaving-string/discuss/31948/8ms-C%2B%2B-solution-using-BFS-with-explanation
    DFS Approach: https://leetcode.com/problems/interleaving-string/discuss/31888/1ms-tiny-DFS-beats-94.57
    
    Current Apporach:
       s1: "aabcc", s2: "dbbca", s3: "aadbbbaccc"
       first we are checking longest common prefix between s2 and s3
       aur DP is: 1 0 0 0 0 0 (0th element for comparing "" with "")
       
       now we are cheking for  longest common prefix between s1 and s3 & storing at dp[0] 
       also checking if we are having prev prefixes as combinations of s1 & s2;
       dp[j] = (common prefix between s2 & s3 till index j and s3[current index] == s1[curr index] )
                or
                (common prefix between s1 & s3 till index j and s3[current index] == s2[curr index] )
       
        1 0 0 0 0 0 
        1 1 1 1 0 0 
        0 1 1 1 0 0 
        0 0 0 0 0 0 
        0 0 0 0 0 0 

    */
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), p = s3.size();

        if (m + n != p) 
            return false;
                
        vector<bool> dp(n + 1);//initialize

        for (int j = 0; j <= n; j++)  
            dp[j] = s2.substr(0, j)==s3.substr(0, j); 
        // here we are storing longest common prefix between s2 & s3
        for(auto el:dp) cout<<el<<" ";cout<<endl;
    
        for (int i = 1; i <= m; i++){
            dp[0] = s1.substr(0, i)==s3.substr(0, i); // common prefix is available b/w s1 & s2 at index i
            for (int j = 1; j <= n; j++)
                dp[j] = (dp[j] && s3[i+j-1]==s1[i-1]) || (dp[j-1] && s3[i+j-1]==s2[j-1]);
            
        for(auto el:dp) cout<<el<<" ";cout<<endl;
        }
        return dp[n];
        
        // bool DP[m+1][n+1];
        // /* bottom up Approach */ not working
        // for(int i=0; i<= m; i++){
        //     for(int j=0; j<= n; j++){
        //         if(i==0 && j==0)
        //             DP[i][j] = true;
        //         else if(i == 0) // for first col, we are checking if our above dp was true && current scene is true
        //             DP[i][j] = ( DP[i][j-1] && s2[j-1] == s3[i+j-1]);
        //         else if(j == 0) // for first row, we are checking if our left dp was true && current scene is true
        //             DP[i][j] = ( DP[i-1][j] && s1[i-1] == s3[i+j-1]);
        //         else // else we are checking if prev left or prev up were true so we can use current as true too.
        //             DP[i][j] = (DP[i-1][j] && s1[i-1] == s3[i+j-1] ) || (DP[i][j-1] && s2[j-1] == s3[i+j-1] );
        //     }
        // }
        // return DP[m][n];
    }
};