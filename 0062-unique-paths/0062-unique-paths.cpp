class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m+1, vector<int>(n+1, -1));
        return getAllUniquePath(m-1,n-1,cache);
        
    }
    int getAllUniquePath(int currRow, int currCol, vector<vector<int>> &cache){
        if(currRow == 0 || currCol == 0){
            return 1;
        }
        if(cache[currRow][currCol] == -1){
            cache[currRow][currCol] = getAllUniquePath(currRow -1, currCol, cache) + getAllUniquePath(currRow, currCol -1, cache);
        }
        return cache[currRow][currCol];
    }
};