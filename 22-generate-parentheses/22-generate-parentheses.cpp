class Solution {
public:
    // top down recursion
    void recursion(int n,int oCnt, int cCnt, vector<string> &res, string &s){
        if(oCnt == n && cCnt == n){
            res.push_back(s);
            return;
        }
        if(oCnt > cCnt){
            if(oCnt != n){
                string ts =s+"(";
                recursion(n,oCnt+1,cCnt,res,ts);
            }
            string ts =s+")";
            recursion(n,oCnt,cCnt+1,res,ts);
        }else{
            string ts =s+"(";
            recursion(n,oCnt+1,cCnt,res,ts);
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        recursion(n,0,0,res,s);
        return res;
    }
};