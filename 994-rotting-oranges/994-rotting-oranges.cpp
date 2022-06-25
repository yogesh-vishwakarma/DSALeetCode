class Solution {
public:
    void dfs(vector<vector<int>>&grid,int x, int y,int r, int c,int count,bool start){
        if(x<0 || x>=r || y<0 || y>=c || grid[x][y]==0|| grid[x][y]<0 && -grid[x][y]<count )
            return;
        if(grid[x][y]==2 && !start)
            return;
            
        grid[x][y]=-count;
        
        dfs(grid,x+1,y,r,c,count+1,false);
        dfs(grid,x,y+1,r,c,count+1,false);
        dfs(grid,x-1,y,r,c,count+1,false);
        dfs(grid,x,y-1,r,c,count+1,false);
    }    
    
    int orangesRotting(vector<vector<int>>& grid) {
            int r=grid.size();
            int c=grid[0].size();
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(grid[i][j]==2){
                        dfs(grid,i,j,r,c,0,true);
                    }
                }
            }
            int ans=0;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(grid[i][j]==1)
                        return -1;
                    ans=max(abs(grid[i][j]),ans);
                }
            }
            return ans;
        }
    

   /* bfs 
    int orangesRotting(vector<vector<int>>& grid){
        
        vector<int> dir={-1,0,1,0,-1}; 
        //used for finding all 4 adjacent coordinates
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q; // bfs queue
        int fresh=0;// fresh orange count
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        int ans=-1; 
        //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                pair<int,int> p=q.front();
                q.pop();
                // instead of using 4 if condition we are using dir vector
                for(int i=0;i<4;i++){
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                    if(r>=0 && r<m && c>=0 && c<n &&grid[r][c]==1){
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                    
                }
            }
            ans++; //incremented after each minute passes
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
        
    }
    */
};