class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
        // vector<int> hashArr(128, 0);
        // for(char el: t){
        //     hashArr[el]++;
        // }
        // int left = 0, validator = t.size();
        // int subStrHead = 0, subStrTail = INT_MAX, strSize = s.size();
        // for(int idx = 0; idx < strSize; idx++){
        //     if(hashArr[s[idx]] > 0){
        //         validator --;
        //     }
        //     hashArr[s[idx]] --;
        //     while(validator == 0 ){
        //         subStrTail = min(subStrTail, idx - left + 1);
        //         subStrHead = left;
        //         if(hashArr[s[left]] == 0){ // making the substring shorter
        //             validator++;
        //         }
        //         hashArr[s[left]]++; left++;
        //     }
        // }
        // return subStrTail == INT_MAX? "" : s.substr(subStrHead, subStrTail);
    }
};