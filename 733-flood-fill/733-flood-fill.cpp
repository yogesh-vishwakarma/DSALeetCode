class Solution {
public:
    
    /* Using DFS
    vector<int> dr={-1,1,0,0};
    vector<int> dc={0,0,1,-1};
    void dfs(vector<vector<int>>&image,int r,int c,int m,int n,int target,int newcolor)
    {
        if(r<0||c<0||r>=m||c>=n||image[r][c]==newcolor||image[r][c]!=target) return;
        image[r][c]=newcolor;
        for(int i=0;i<dr.size();i++)
        {
            dfs(image,r+dr[i],c+dc[i],m,n,target,newcolor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size(),n=image[0].size();
        dfs(image,sr,sc,m,n,image[sr][sc],newColor);
        return image;
    }*/
    void bfs(vector<vector<int>>& image,int sr,int sc, int newColor, int n, int m){
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        int dx[4]={0,0,1,-1};// directional array
        int dy[4]={1,-1,0,0};// directional array
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                // here we can use directional array to move into all direction
               int newX=x+dx[i];
               int newY=y+dy[i];
               if(newX>=0 && newY>=0 && newX<n && newY<m && image[newX][newY]==color){
                   q.push({newX,newY});
                   image[newX][newY]=newColor;
               }
            }
        }   
     }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        queue<int> BFS;
        if(image[sr][sc]!=newColor)
            bfs(image, sr, sc,  newColor,n,m); 
        return image;
    }
};