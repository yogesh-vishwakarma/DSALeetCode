class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
    
    bool helper(vector<vector<char>> &board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                // main logic
                if(board[i][j] == '.'){
                    for(char c='1';c<='9';c++){
                        if(checkvalidity(i,j,board,c)){
                            board[i][j] = c;
                            if(helper(board))
                                return true;// we only need 1 soln so we return
                            else
                                board[i][j] = '.';// backtracking step
                        } 
                    }
                    return false;
                }
                // end main logic
              }
            }
        return true;
    }
    
    bool checkvalidity(int row, int col, vector<vector<char>> board, char c){
        for(int i=0;i<9;i++)
            // row & column & smaller 3*3 matric check
            if(board[row][i] == c || board[i][col] == c || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        return true;
    }
};