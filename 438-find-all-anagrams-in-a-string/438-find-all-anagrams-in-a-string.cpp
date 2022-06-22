class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size()> s.size())
            return ans;
        for(int i(0); i<=(s.size()-p.size());i++){
            string temp; 
            temp.append(s,i,p.size());
            if(ifAnagram(temp,p))
                ans.push_back(i);
        }
        return ans;
    }
    
    
    bool ifAnagram(string s, string t){
        if (s.length() != t.length())
            return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};