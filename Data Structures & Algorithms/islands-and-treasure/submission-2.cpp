class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size(); 
        queue<pair<int, int>> q;
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(grid[i][j] == 0){ 
                    q.push({i, j}); // All treasure sources in q
                }
            }
        }
        int INF = 2147483647;
        while(!q.empty()){ // Go from treasure to land
            auto[r, c] = q.front(); q.pop();
            for(int i = 0; i< 4; i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if(nr >= 0 && nc >=0 && nr < grid.size() && nc < grid[0].size()
                && grid[nr][nc] == INF){
                    grid[nr][nc] = grid[r][c] + 1; // increment the movement by 1
                    q.push({nr, nc});
                }
            }
        }
    }
};
