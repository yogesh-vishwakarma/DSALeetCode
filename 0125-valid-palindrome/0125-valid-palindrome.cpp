class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())return 1;
        int start=0,end=s.size();
        while(start<end){
            if(!isalnum(s[start])){
                start++;continue;
            }
            if(!isalnum(s[end])){
                end--;continue;
            }
            if(toupper(s[start++])!=toupper(s[end--]))return 0;
        }
        return 1;
    }
};