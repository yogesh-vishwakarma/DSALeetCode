class Solution {
public:
    // here we are using dfs to find out size of island
   int solve(vector<vector<int>> &grid, int i, int j){
        int M = grid.size(); int N = grid[0].size();
       // base condition
        if(i >= M or i < 0 or j >= N or j < 0  or grid[i][j] == 0)
            return 0;
       /* we are changing the island values to 0 
       so we don't come again on already visited island*/
       grid[i][j] = 0;
        return (1   + solve(grid, i + 1, j) 
                    + solve(grid, i , j + 1) 
                    + solve(grid, i - 1, j)
                    + solve(grid, i, j - 1));
       
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int M = grid.size(); int N = grid[0].size();
        int max_area = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                max_area = max(max_area, solve(grid, i, j));
            }
        }
        return max_area;
    }
};