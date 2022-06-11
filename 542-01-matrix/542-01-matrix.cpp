class Solution {
public:
   vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int> (m, INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            int i = top.first;
            int j = top.second;
            for(int c=0; c<4; c++) {
                int ni = i + di[c];
                int nj = j + dj[c];
                if(ni>=0 && ni<n && nj>=0 && nj<m) {
                    if(ans[ni][nj] > ans[i][j]+1) {
                        ans[ni][nj] = ans[i][j]+1;
                        q.push({ni, nj});
                    }
                }
            }
        }
        return ans;
    }
};