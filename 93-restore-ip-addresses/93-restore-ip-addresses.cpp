class Solution {
public:
    bool isValid(string s){
        int len=s.size();
        if(s[0]=='0' && len>1)  
            return false;
        int num=stoi(s);
        if(num>=0 && num<=255)  
            return true;
        return false;
    }
    void solve(string s, int st, string path, int cuts, vector<string>& res)
    {
        if(cuts<=0 && st<s.size())  //if cuts exhausted, but still there is execess string
            return;
        
        if(cuts==0 && st>=s.size()){    //if cuts exhausted, entire string is also covered, then push in res
            path = path.substr(1, path.size()-1);
            res.push_back(path);
            return;
        }
        for(int i=st; i<s.size(); i++)  //trying partition, until i becomes invalid
        {
            string tmp=s.substr(st, i-st+1);  
            if(isValid(tmp)){  //if partition is valid, then proceed with next recursion
                solve(s, i+1, path + "." + tmp, cuts-1, res);
            }
            else break;  //if curr partition is invalid, then next i positions will also be invalid
        }
    }
    vector<string> restoreIpAddresses(string s){
        string path;
        vector<string> res;
        solve(s, 0, path, 4, res);
        return res;
    }
};