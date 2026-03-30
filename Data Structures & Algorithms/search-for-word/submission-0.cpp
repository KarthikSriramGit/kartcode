class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(dfs(board, word, r, c, 0)){
                    return true;
                }
            }
        }
    }
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i){
        if(i == word.size()){
            return true;
        }
        if(r< 0 || c < 0 || r >=board.size() || c >= board[0].size()|| 
        board[r][c] != word[i] || board[r][c] == '#'){
            return false;
        }
        board[r][c] = '#';
        bool res = dfs(board, word, r+1, c, i+1) || 
                    dfs(board, word, r-1, c, i+1) ||
                    dfs(board, word, r, c+1, i+1) ||
                    dfs(board, word, r, c-1, i+1);
        board[r][c] = word[i];
        return res;
    }
};
