class Solution {
public:
    string decodeString(string s) {
        int i =0;
        return topDownRec(s,i);
    }
    
    string topDownRec(string s, int& i){
        int n = s.size(); string ans;
        
        while( i < n && s[i] !=']' ){
            
            if( !isdigit(s[i]) ){
                ans += s[i++];
                continue;
            }
            
            int k = 0;
            while( i<n && isdigit(s[i]) )
                k = k*10 + ( s[i++] - '0' );
           
            i++; // egnoring '['
            string temp = topDownRec(s, i);
            i++; // egnoring ']'
            
            while(k-- > 0)
                ans+=temp;
        }
        return ans;
    }
    
    string decodeStringItr(string s){
        string ans; int k = 0; string temp;
        for(int i=0;i<s.size();i++){
            if(s[i] == ']'){
                while(k--){
                    ans +=temp;
                }
                k=0, temp =""; continue;
            }
            else if(s[i] == '[')
                continue;
            else if( isdigit(s[i]) )
                k = k*10 + (s[i]-'0');
            else
                   temp += s[i];
        }
        return ans;
    }

};
