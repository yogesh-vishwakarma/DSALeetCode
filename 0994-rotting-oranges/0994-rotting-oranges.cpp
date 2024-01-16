class Solution {
public:
//     void dfs(vector<vector<int>>&grid,int x, int y,int r, int c,int count,bool start){
//         if(x<0 || x>=r || y<0 || y>=c || grid[x][y]==0|| grid[x][y]<0 && -grid[x][y]<count )
//             return;
//         if(grid[x][y]==2 && !start)
//             return;
            
//         grid[x][y]=-count;
        
//         dfs(grid,x+1,y,r,c,count+1,false);
//         dfs(grid,x,y+1,r,c,count+1,false);
//         dfs(grid,x-1,y,r,c,count+1,false);
//         dfs(grid,x,y-1,r,c,count+1,false);
//     }    
    
//     int orangesRotting(vector<vector<int>>& grid) {
//             int r=grid.size();
//             int c=grid[0].size();
//             for(int i=0;i<r;i++){
//                 for(int j=0;j<c;j++){
//                     if(grid[i][j]==2){
//                         dfs(grid,i,j,r,c,0,true);
//                     }
//                 }
//             }
//             int ans=0;
//             for(int i=0;i<r;i++){
//                 for(int j=0;j<c;j++){
//                     if(grid[i][j]==1)
//                         return -1;
//                     ans=max(abs(grid[i][j]),ans);
//                 }
//             }
//             return ans;
//         }
    

   /* bfs */
    int orangesRotting(vector<vector<int>>& grid){
        int maxRow = grid.size(), maxCol = grid[0].size();
        
        queue <pair <pair<int, int>, int>> bfsQ; // {{row, col}, time}
        int vis[maxRow][maxCol]; // bfs visited
        
        int totalFreshOranges = 0;
        for(int row = 0; row < maxRow; row ++){
            for(int col = 0; col < maxCol; col++){
                if(grid[row][col] == 2){
                    bfsQ.push({{row, col}, 0});
                    vis[row][col] = 2;
                }else{
                    vis[row][col] = 0;
                    totalFreshOranges += grid[row][col] == 1? 1 : 0;
                }
            }
        }
        int minTime = 0;
        int dRowCol[] = {-1, 0, 1, 0, -1};
        while(!bfsQ.empty()){
            int row = bfsQ.front().first.first;
            int col = bfsQ.front().first.second;
            int time = bfsQ.front().second;
            minTime = max(minTime, time);
            bfsQ.pop();
            for(int i = 0; i<4; i++ ){
                int nRow = row + dRowCol[i];
                int nCol = col + dRowCol[i+1];
                if(nRow >= 0 && nRow < maxRow && nCol >= 0 && nCol < maxCol
                   && vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1){
                    bfsQ.push({{nRow, nCol}, time + 1});
                    vis[nRow][nCol] = 2;
                    totalFreshOranges--;
                }
            }
        }
        return totalFreshOranges > 0? -1: minTime;
    }
};