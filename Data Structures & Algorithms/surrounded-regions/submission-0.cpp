class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board) {
        bfs(board);
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    void bfs(vector<vector<char>>& board){
        queue<pair<int, int>> q;
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(r == 0 ||  r == board.size()-1 || c == 0 || c == board[0].size()-1 
                && board[r][c] == 'O'){
                    q.push({r,c});
                }
            }
        }
        while(!q.empty()){
            auto[r,c] = q.front(); q.pop();
            if(board[r][c] == 'O'){
                board[r][c] = 'T';
                for(int i = 0; i < 4; i++){
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];
                    if(nr >= 0 && nc >=0 && nr < board.size() && nc < board[0].size()){
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
};
