class Solution {
    vector<string> mp;
    unordered_map<string,vector<pair<int,string>>> common;
    int cur = 0;
    
    void splitMe(string& s){
        string temp,path;
        stringstream S(s);
        getline(S,temp,' ');
        mp.push_back(temp);
        while(getline(S,temp,' ')){
            int loc = (int)(temp.find('('));
            path = temp.substr(0,loc);
            temp = temp.substr(loc);
            common[temp].emplace_back(cur,path);
        }
        cur++;
    }
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        // custom function to split the paths and store in map
        for(string& s:paths){
            splitMe(s);
        }
        vector<vector<string>> ans;
        int cur = 0;
        /* checking that if for a path*/
        for(auto ptr = common.begin(); ptr != common.end(); ptr++){
            if(ptr->second.size() == 1)
                continue;
            ans.push_back({});
            for(pair<int,string>& p: ptr->second){
                ans[cur].push_back(mp[p.first]+"/"+p.second);
            }
            cur++;
        }
        return ans;
    }
};