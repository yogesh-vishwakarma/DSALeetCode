class Solution {
public:
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
    //     priority_queue<pair<int,vector<int>>> pq;
    //     for(int i=0;i<points.size();i++){
    //         if(pq.size() < k){
    //             int dist = pow(points[i][0],2) + pow(points[i][1],2);
    //             pq.push({dist,{points[i][0],points[i][1]}});
    //         }
    //         else{
    //             int dist = pow(points[i][0],2) + pow(points[i][1],2);
    //             pq.push({dist,{points[i][0],points[i][1]}});
    //             pq.pop();
    //         }
    //     }
    //     vector<vector<int>> ans;
    //     while(!pq.empty()){
    //         ans.push_back(pq.top().second);
    //         pq.pop();
    //     }
    //     return ans;
    // }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [] (vector<int> &a, vector<int> &b) {
            int da = a[0]*a[0] + a[1]*a[1];
            int db = b[0]*b[0] + b[1]*b[1];
            return da < db;
        };
        // std::nth_element() has the requirement of having O(n) complexity
        // Reference: https://stackoverflow.com/a/10352509
        nth_element(points.begin(), points.begin()+k-1, points.end(), comp);
        points.resize(k);
        return move(points);
    }
};