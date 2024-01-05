class Solution {
public:
    int countSubstrings(string str) {
        int length = str.length(), count = 0; // Variable to store the count of palindromic substrings

        for (int center = 0; center < length; center++) {
            int left = center - 1;
            int right = center;

            // Expand around the center for consecutive identical characters
            while (right < length - 1 && str[right] == str[right + 1]) {
                right++;
            }

            // Count substrings with consecutive identical characters
            count += (right - left) * (right - left + 1) / 2;

            // Move the center to the right of consecutive identical characters
            center = right++;

            // Expand around the center for palindromes
            while (left >= 0 && right < length && str[right] == str[left]) {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};