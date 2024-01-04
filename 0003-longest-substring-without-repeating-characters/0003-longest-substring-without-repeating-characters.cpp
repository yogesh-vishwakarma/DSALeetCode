class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       // int size = s.size();
       //  int maxLength = 0;
       //  vector<int> charIndex(128, -1);
       //  for(int left =0, right = 0; right < size; right ++){
       //      if(charIndex[s[right]] >= left){
       //          left = charIndex[s[right]] + 1;
       //      }
       //      charIndex[s[right]] = right;
       //      maxLength = max(maxLength, right -left + 1);
       //  }
       //  return maxLength;
        
        int stringSize = s.size(), result = 0;
        vector<int> hashArr(128, -1);
        int left = 0;
        for(int idx = 0; idx < stringSize; idx++ ){
            int prevIndex = hashArr[s[idx]];
            if(prevIndex >= left){
                left = prevIndex + 1;
            }
            hashArr[s[idx]] = idx;
            result = max(result, idx - left + 1);
        }
        return result;
    }
};