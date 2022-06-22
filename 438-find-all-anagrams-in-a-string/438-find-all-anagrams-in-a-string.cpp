// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> ans;
//         if(p.size()> s.size())
//             return ans;
//         for(int i(0); i<=(s.size()-p.size());i++){
//             string temp; 
//             temp.append(s,i,p.size());
//             if(ifAnagram(temp,p))
//                 ans.push_back(i);
//         }
//         return ans;
//     }
    
    
//     bool ifAnagram(string s, string t){
//         if (s.length() != t.length())
//             return false;
//         int n = s.length();
//         int counts[26] = {0};
//         for (int i = 0; i < n; i++) { 
//             counts[s[i] - 'a']++;
//             counts[t[i] - 'a']--;
//         }
//         for (int i = 0; i < 26; i++)
//             if (counts[i]) return false;
//         return true;
//     }
// };

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int map1[26] = {0};
        int map_move[26] = {0};
        vector<int> ret;
        int i, j;
        for(i = 0; i < p.length(); i++)
            map1[p[i]-'a']++;
        i = j = 0;
        for(j = 0; j < s.length(); j++) {
            map_move[s[j]-'a']++;
            if (j-i+1 == p.length() && map1[s[j]-'a'] == map_move[s[j]-'a']) {
                ret.push_back(i);
                map_move[s[i]-'a']--;
                i++;
            }
            else if (map1[s[j]-'a'] >= map_move[s[j]-'a'])
                continue;
            else if (map1[s[j] - 'a'] && map1[s[j] - 'a'] < map_move[s[j]-'a']) {
                while(map1[s[j]-'a'] < map_move[s[j]-'a']) {
                    map_move[s[i]-'a']--;
                    i++;
                }
            }
            else {
                while(i!=j) {
                    map_move[s[i]-'a']--;
                    i++;
                }
                i++;
            }
        }
        return ret;
    }
};