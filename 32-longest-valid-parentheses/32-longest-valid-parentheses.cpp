class Solution {
public:
    int longestValidParentheses(string s) {
        //taking a stack and initializing it with -1 in case of ) to prevent stack underflow
        
        stack<int> st;
        st.push(-1);
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push(i);//if ( then push the index in stack
            else
            {
                // if it is close then pop the stack  and check it is empty or not if it is empty then push current value to it because if there is another ) then we can not pop our stack if it is empty
            
                st.pop();
                if(st.empty()) st.push(i);
                // if it is not empty then find the length between the (current index i and stack top index) and store the max value in ans
                else count=max(count,i-st.top());
            }
        }
        return count;
    }
};