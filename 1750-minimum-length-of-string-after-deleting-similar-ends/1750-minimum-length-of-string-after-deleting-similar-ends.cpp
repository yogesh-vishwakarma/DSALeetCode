class Solution {
public:
    int minimumLength(string s) {
        int prefixP = 0, suffixP = s.size() -1;
        while(prefixP < suffixP){
            cout << prefixP << suffixP << endl;
            if(s[prefixP] != s[suffixP]){
                break;
            }
            while(prefixP + 1 < suffixP && s[prefixP] == s[prefixP + 1]) prefixP++;
            while(suffixP - 1 > prefixP && s[suffixP] == s[suffixP - 1]) suffixP--;
            prefixP++; suffixP--;
        }
        return suffixP - prefixP + 1;
    }
};