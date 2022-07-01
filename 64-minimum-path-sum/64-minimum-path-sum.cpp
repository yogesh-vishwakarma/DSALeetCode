class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(i==0 && j==0)
                    continue;
                if(i>0 && j==0) // first row (we can only go down)
                    grid[i][j] +=grid[i-1][j];
                else if(j>0 && i==0) // first col (we can only go right)
                    grid[i][j] +=grid[i][j-1];
                else // choose min path
                    grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[row-1][column-1];
    }
};