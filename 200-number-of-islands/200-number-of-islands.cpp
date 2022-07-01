class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res(0);
        for(int i(0);i<grid.size();i++){
            for(int j(0);j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    // sinkIslandBFS(grid,i,j);
                    sinkIslandDFS(grid,i,j);
                    res++;
                    grid[i][j] = '0';
                }
            }
        }
        return res;
    }
    
    void sinkIslandDFS(vector<vector<char>> &grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j]='0';
        int dir[] = {-1,0,1,0,-1};
        for(int k=0;k<4;k++)
            sinkIslandDFS(grid,i+dir[k],j+dir[k+1]);
    }
    
    void sinkIslandBFS(vector<vector<char>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        int offsets[] = {0,1,0,-1,0}; //Offsets for visiting neighbouring elements. 
        //Represents [0,1],[1,0],[0,-1],[-1,0].
        queue<pair<int,int>> todo;
        todo.push({i,j});
        while(!todo.empty()){
            pair<int, int> p = todo.front();
            todo.pop();
            for(int k=0; k<4; k++){
                int r = p.first + offsets[k];
                int c = p.second + offsets[k+1];
                if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == '1'){
                    grid[r][c] = '0';
                    todo.push({r,c});
                }
            }
        }
    }
};