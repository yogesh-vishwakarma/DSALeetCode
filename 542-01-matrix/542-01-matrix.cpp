class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int rows = matrix.size(), cols = matrix[0].size();
        if(rows == 0)
            return matrix;
        vector<vector<int>> ans(rows, vector<int>(cols,INT_MAX - 10000));// as provided in constrains
        
        
        /*Here we will use bottom up approach, DP tabulation 
            We are creating a 2d vector with max size elements.
            then we are checking for following conditions.
            if that el itself is zero: mark dp as zero too.
            for other elements we will check it's distance with zero.
            this is kind of looks like BFS traversal.
        */
        
        // here we are checking left & top in forward flow
        for(int i(0);i<rows;i++){
            for(int j(0);j<cols;j++){
                if(matrix[i][j] == 0)
                    ans[i][j]=0;
                else{
                    if(i>0)
                        ans[i][j] = min(ans[i][j], ans[i-1][j] +1); // comparing with top
                    if(j>0)
                        ans[i][j] = min(ans[i][j], ans[i][j-1] +1); // comparing with left
                }
            }
        }
        // check bottom & right in backward flow
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1); // comparing with bottom
                if (j < cols - 1)
                    ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1); // comparing with right
            }
        }
        // printAns(ans);
        return ans;
    }
    
    void printAns(vector<vector<int>> nums){
        cout <<endl<<endl;
        for(auto row: nums){
            for(auto el: row)
                cout << el<<"\t";
            cout <<endl;
        }
    }
};