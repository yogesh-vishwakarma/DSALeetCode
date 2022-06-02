class Solution {
public:
string reverseWords(string s) {
        stringstream str(s);
        string word, answer;
        while (str >> word){
            reverse(word.begin(), word.end());
            answer.append(word + " ");
        }
        answer.pop_back();
        return answer;
    }
};