class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        backtrack(0, board);
        return result;
    }
    void backtrack(int i, vector<string>& board){
        if(i == board.size()){
            result.push_back(board);
            return;
        }
        for(int j = 0; j < board.size();j++){
            if(isSafe(i,j,board)){
                board[i][j] = 'Q';
                backtrack(i+1, board);
                board[i][j] = '.';
            }
        }
    }
    bool isSafe(int r, int c, vector<string>& board){
        for(int i = r-1; i >=0; i--){
            if(board[i][c] == 'Q'){ return false;}
        }
        for(int i = r-1, j = c-1; i >=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};
