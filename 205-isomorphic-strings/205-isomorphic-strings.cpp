class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char d[256], e[256];
        int i;
        for (i = 0; i < 256; i++)
            d[i] = 0;
        for (i = 0; i < 256; i++)
            e[i] = 0;
        
        for (i = 0; i < s.size(); i++) {
            if (d[s[i]] == 0 and e[t[i]] == 0) {
                d[s[i]] = t[i];
                e[t[i]] = s[i];               
            }
            else if (d[s[i]] != t[i] or e[t[i]] != s[i])
                return false;
        }
        return true;
    }
};