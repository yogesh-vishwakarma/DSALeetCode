class Solution {
public:
   string minWindow(string s, string t) {
        vector<int> hashArr(128, 0);
        for (char el : t) {
            hashArr[el]++;
        }

        int left = 0, counter = t.size();
        int subStrHead = 0, subStrTail = INT_MAX, strSize = s.size();
        for (int idx = 0; idx < strSize; idx++) {
            if (hashArr[s[idx]] > 0) {
                counter--;
            }
            hashArr[s[idx]]--;
            while (counter == 0) {
                if (subStrTail > idx - left + 1) {
                    subStrTail = idx - left + 1;
                    subStrHead = left;
                }
                hashArr[s[left]]++;
                if (hashArr[s[left]] > 0) {
                    counter++;
                }
                left++;
            }
        }
        return subStrTail == INT_MAX ? "" : s.substr(subStrHead, subStrTail);
    }
};