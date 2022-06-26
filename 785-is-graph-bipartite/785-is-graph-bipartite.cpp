class Solution {
public:
    // TC: O(N+E)
    // SC: O(N+E) + O(N) + O(N)
    bool isBipartite(vector<vector<int>>& graph) {
        int vCount = graph.size();
        vector<int> color(vCount,-1);
        
        for(int i=0;i<vCount;i++){
            if(color[i] != -1)// means already visited/colored
                continue;
            // if(!biPartiteBFS(i,graph,color))
            //     return false;
            
            if(!biPartiteDFS(i,graph,color))
                return false;
            
        }
        return true;
    }
    bool biPartiteDFS(int node, vector<vector<int>>& adj, vector<int> &color){
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                if(!biPartiteDFS(it, adj, color))
                    return false; 
            } 
            else if(color[it] == color[node]) 
                return false; 
        }
        return true; 
    }
    
    bool biPartiteBFS(int src, vector<vector<int>>& adj, vector<int> &color){
        queue<int> bfs;
        bfs.push(src);
        color[src] = 1;
        while(!bfs.empty()){
            int curr = bfs.front();
            bfs.pop();
            
            for(auto itr: adj[curr]){
                if(color[itr] == -1){
                    color[itr] = 1 - color[curr];//1->0 & 0->1 
                    bfs.push(itr);
                }
                else if(color[itr] == color[curr])
                    return false;
            }
        }
        return true;
    }
};