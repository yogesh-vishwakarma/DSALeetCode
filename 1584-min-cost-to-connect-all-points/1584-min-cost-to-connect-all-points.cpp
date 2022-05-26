class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
          
        int n = points.size();  // no of nodes
        
        vector<vector<int>> graph(n, vector<int>(n));  //  graph
        
       /// assign distance/weights to the nodes 
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) { 
                graph[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }
        
        
        /// visited vector 
        vector<int>visited(n+1,0);
        
        // min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0}); // <weight, node>
        
        // to calculate the cost of Mst
        int ans=0;
      
        // Prim Algo
        while(!q.empty()){
    
            auto curr=q.top();
            q.pop();
            
            // weight/distance if the node
            int weight=curr.first;
            int src=curr.second;// source node
            
            // check for visited nodes
            if(visited[src])continue;
            ans+=weight;
            visited[src]=1;
            
            for(int i=0;i<n;i++){
                if(visited[i]==0){
                    q.push(make_pair(graph[src][i],i));
                }
            }
        }
        
        return ans;
    }
};