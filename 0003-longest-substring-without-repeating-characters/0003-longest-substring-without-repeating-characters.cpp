class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int stringLength = s.size(), maxLength = 0;
        vector<int> charAsciiIndex(128, -1);

        if (stringLength < 2) {
            return stringLength;
        }

        int startIdx = 0; // Starting index of the current substring

        for (int idx = 0; idx < stringLength; idx++) {
            if (charAsciiIndex[s[idx]] != -1) {
                int lastIndex = charAsciiIndex[s[idx]];
                startIdx = max(startIdx, lastIndex); // Update the start index
            }
            maxLength = max(maxLength, idx - startIdx + 1);
            charAsciiIndex[s[idx]] = idx + 1; // Update the last index (+1)
        }

        return maxLength;
    }
};