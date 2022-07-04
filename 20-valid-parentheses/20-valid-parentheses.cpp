class Solution {
public:
    
    
    bool isValid(string s) {
        if(s.size()%2 != 0)
            return false;
        unordered_map<char,char> mp;
        mp['[']=']'; mp['{']='}'; mp['(']=')';
        
        stack<char> st;
        for(auto el :  s ){
            if(el == '(' || el == '{' || el == '[')
                st.push(el);
            else{
                if(!st.empty() && el == mp[st.top()])
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
    
};