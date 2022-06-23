class Solution {
public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> subs;
//         vector<int> sub;
//         Backtracking(nums, 0, sub, subs);
//         return subs;
//     }
    
//     void Backtracking(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
//         subs.push_back(sub);
//         for (int j = i; j < nums.size(); j++) {
//             sub.push_back(nums[j]);
//             subsets(nums, j + 1, sub, subs);
//             sub.pop_back();
//         }
//     }
    
    /*iterative*/
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}}; // creating a blanck vector of vector
        for (int el : nums) {
            int n = subs.size();
            /*
             for every vector inside subs, we are taking ith vector from ans & 
                adding nums element in that vector
             
             EX: for each element of nums = [1,2,3];
             
             i=0; subs = [[], [1]] // el = 1 & n = 1 so subs = [[]] <- push (subs[0]=[]<-push el = 1);
             
             i=0; subs = [[],  [1], [2] ]
             i=1; subs = [[],  [1], [2], [1,2] ]
             
             i=0; subs = [[],  [1], [2], [1,2], [3] ]
             i=1; subs = [[],  [1], [2], [1,2], [3], [1,3] ]
             i=2; subs = [[],  [1], [2], [1,2], [3], [1,3], [2,3] ]
             i=3; subs = [[],  [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3] ]
            */
            
            for (int i = 0; i < n; i++) {                
                subs.push_back(subs[i]);
                subs.back().push_back(el);
            }
        }
        return subs;
    }
    
    /*bitwise*/
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     int n = nums.size(), p = 1 << n;
    //     vector<vector<int>> subs(p);
    //     for (int i = 0; i < p; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if ((i >> j) & 1) {
    //                 subs[i].push_back(nums[j]);
    //             }
    //         }
    //     }
    //     return subs;
    // }
};