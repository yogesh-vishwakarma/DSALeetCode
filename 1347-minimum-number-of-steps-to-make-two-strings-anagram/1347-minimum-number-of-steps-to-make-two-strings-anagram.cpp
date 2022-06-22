class Solution {
public:
    int minSteps(string s, string t) {
        int arr[26] = {0}; int ans(0);
        for(int i(0);i<s.size();i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(auto itr : arr)
            if(itr > 0)
                ans+=itr;
        return ans;
    }
};