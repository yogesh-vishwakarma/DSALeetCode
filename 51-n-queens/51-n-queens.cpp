class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string row(n,'.');
        vector<string> board(n,row);
        
        backtracking(n, result, board, 0);
        return result;
    }
    
    void backtracking(int n, vector<vector<string>> &ans, vector<string> &board, int col){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row(0);row<n;row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                backtracking(n, ans, board, col+1);
                board[row][col] = '.';
            }
        }
    }
    
    bool isSafe(int row, int col ,vector<string> board,int n){
        int duprow = row;
        int dupcol = col;
        
        
        // check upper diagonal
        while(row>=0 && col >= 0){
            if(board[row--][col--] == 'Q')
                return false;
        }
        
        // check row's prev records
        col = dupcol; row = duprow;
        while(col >= 0){
            if(board[row][col--] == 'Q')
                return false;
        }
        
        // check lower diagonal
        col = dupcol; row = duprow;
        while( col>=0 && row <n){
            if(board[row++][col--] == 'Q')
                return false;
        }
        
        
        return true;
    }
};