class Solution {
public:
   int MatchingPair(char c1, char c2)
    {
        if (c1 == '(' && c2 == ')' || c1 == '{' && c2 == '}' || c1 == '[' && c2 == ']')
            return 1;
        else
            return 0;
    }

    bool isValid(string s) 
    {    
    stack<char> St;

    for(int i=0;i<s.size();i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' )
        {   
            St.push(s[i]);
        }
        
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {   
            if(St.empty()) return false;
            else if (MatchingPair(St.top(),s[i])) St.pop();
            else return false;
        }
    } 
    if (St.empty())
        return true;
    else
        return false;
    }
};