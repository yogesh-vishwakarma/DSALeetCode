class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int maxLength = 0;
        vector<int> charIndex(128, -1);
        for(int left =0, right = 0; right < size; right ++){
            if(charIndex[s[right]] >= left){
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLength = max(maxLength, right -left + 1);
        }
        return maxLength;
    }
};