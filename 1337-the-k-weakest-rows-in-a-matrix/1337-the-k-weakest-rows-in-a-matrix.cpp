class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<mat.size();i++)
        { 
            int count = 0;
            auto j = lower_bound(mat[i].begin(),mat[i].end(),0,greater<int>());
            pq.push(make_pair(j-mat[i].begin(),i));
            if(pq.size()>k)
                pq.pop();
        }  
        vector<int> u(k);
        while(!pq.empty())
        {
            u[--k] = pq.top().second;
            pq.pop();
        }
        return u;
    }
};