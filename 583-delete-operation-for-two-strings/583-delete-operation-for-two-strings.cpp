class Solution {
public:
    int lcs(string a, string b)
    {
        int n1=a.size();
        int n2=b.size();
        int dp[n1+1][n2+1];
        for(int i=0;i<n1+1;i++)
        {
            for(int j=0;j<n2+1;j++)
            {
                if(i==0 or j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<n1+1;i++)
        {
            for(int j=1;j<n2+1;j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
    int minDistance(string word1, string word2) {
        int lcs_size = lcs(word1,word2);
        int ans = word1.size() + word2.size() - (2*lcs_size); // Can be broken down into (Word1.size() - LCS) + (Word2.size() - LCS)
        return ans;
    }
};