class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> seen;
        for(vector<char> row : board){
            for(char c : row){
                if(c == '.'){
                    continue;
                }
                if(seen.count(c)){
                    return false;
                }
                seen.insert(c);
            }
           seen.clear();
        }
        seen.clear();
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[j][i] == '.'){
                    continue;
                }
                if(seen.count(board[j][i])){
                    return false;
                }
                seen.insert(board[j][i]);
            }
            seen.clear();
        }
        seen.clear();
        for(int square = 0; square < 9; square++){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if(board[row][col] == '.') continue;
                    if(seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]); 
                }
            }
            seen.clear();
        }
        return true;
    }
};
