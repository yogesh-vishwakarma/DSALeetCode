// good post : https://leetcode.com/problems/out-of-boundary-paths/discuss/657850/Evolve-from-brute-force-to-dp

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        constexpr std::size_t MAX_BOARD_SIZE = 50;
        constexpr int MOD_MAGIC_NUMBER = 1000000007;
        
        int sum = 0;
        
        // Build a board of with width and height of MAX N (50) plus out of bounds edges
        // on each side.
        std::array<std::array<int, MAX_BOARD_SIZE + 2>, MAX_BOARD_SIZE + 2> board{};
        
        // Place the ball at its initial position
        board[i+1][j+1] = 1;
        
        // Progress board state N times
        for (int x = 0; x < N; ++x) {
            
            // Make a new array that we will use as next board state
            std::array<std::array<int, MAX_BOARD_SIZE + 2>, MAX_BOARD_SIZE + 2> new_board{};
            
            // For each number on the board, add it to each of its adjacent tiles
            for (int k = 1; k < m + 1; ++k) {
                for (int l = 1; l < n + 1; ++l) {
                    int ball_count = board[k][l];
                    if (ball_count == 0) { continue; }
                    new_board[k-1][l  ] = (new_board[k-1][l  ] + ball_count) % MOD_MAGIC_NUMBER;
                    new_board[k  ][l+1] = (new_board[k  ][l+1] + ball_count) % MOD_MAGIC_NUMBER;
                    new_board[k+1][l  ] = (new_board[k+1][l  ] + ball_count) % MOD_MAGIC_NUMBER;
                    new_board[k  ][l-1] = (new_board[k  ][l-1] + ball_count) % MOD_MAGIC_NUMBER;
                }
            }
            
            // Copy new board state over old board state
            board = new_board;
            
            // Add out of bounds states to the running sum (mod the magic number)
            for (int x = 0; x <= n  ; ++x) { sum = (sum + board[0  ][x  ]) % MOD_MAGIC_NUMBER; }
            for (int x = 0; x <= m  ; ++x) { sum = (sum + board[x  ][n+1]) % MOD_MAGIC_NUMBER; }
            for (int x = 1; x <= n+1; ++x) { sum = (sum + board[m+1][x  ]) % MOD_MAGIC_NUMBER; }
            for (int x = 1; x <= m+1; ++x) { sum = (sum + board[x  ][0  ]) % MOD_MAGIC_NUMBER; }
        }
        
        return sum;
    }
};