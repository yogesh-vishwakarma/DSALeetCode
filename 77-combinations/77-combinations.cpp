class Solution {
public:
    /* iterative approach */
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0){
			p[i]++;
			if (p[i] > n) 
                i--;
			else if (i == k - 1) 
                result.push_back(p);
			else 
                p[++i] = p[i];
		}
		return result;
    }
    
    
    /*
    Recusrsive approach 
    vector<vector<int>> ans;
    vector<int> p;
    vector<vector<int>> combine(int n, int k) {
        solve(1, n, k);
        return ans;
    }
    
    void solve(int index, int n, int k){
        if(p.size() == k){
            ans.push_back(p);
            return;
        }
        
        for(; index <= n; index++){
            p.push_back(index);
            solve(index + 1, n , k);
            p.pop_back();
        }
    }*/
};