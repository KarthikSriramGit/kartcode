class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1 , 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == '1'){
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }
    void bfs(vector<vector<char>>& grid, int row, int col){
        queue<pair<int, int>> q;
        grid[row][col] = '0'; // mark seen
        q.push({row, col});
        while(!q.empty()){
            auto node = q.front(); q.pop();
            int r = node.first, c = node.second;
            for(int i = 0; i < 4; i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if(nr >= 0 && nr < grid.size() && 
                    nc >=0 && nc < grid[0].size() &&
                    grid[nr][nc] == '1'){
                        q.push({nr, nc});
                        grid[nr][nc] = '0';
                    }
            }
        }
    }
};
