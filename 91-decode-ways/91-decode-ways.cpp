class Solution {
public:
    int numDecodings(string s) {
        vector<int> DP(s.size()+1,1);
        
        for(int i=s.size()-1;i>=0;i--){
            s[i]=s[i]-'0';
            if(s[i]==0)
                DP[i]=0;
            else
                DP[i] = DP[i+1];
            
            // cout <<i<<"\t"<<s[i]<<"\t"<<DP[i]<<endl;
            if(i!=s.size()-1 && (s[i]==1 || (s[i]==2 && s[i+1]<7 ))){
                DP[i] += DP[i+2];
            }
        }
        return DP[0];
    }
};