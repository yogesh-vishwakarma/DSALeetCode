class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
        {
            return 0;
        }
        int length = 1;
        std::unordered_map<char, int> occ;
        for (int i = 0, j = 0; i < s.length(); ++i)
        {
            if (occ.find(s[i]) != occ.end())
            {
                j = std::max(j, occ[s[i]] + 1);
            }
            length = std::max(length, i - j + 1);
            occ[s[i]] = i;
        }
        
        return length;
    }
};