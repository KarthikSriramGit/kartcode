class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0},{0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int area = 0;
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(grid[i][j] == 1) area = max(area, bfs(grid, i, j));
            }
        }
        return area;
    }
    int bfs(vector<vector<int>>& grid, int row, int col){
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 0; // visited
        int res = 1; // first block
        while(!q.empty()){
            auto[r, c] = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if(nr >= 0 && nr < grid.size() && nc >=0 && nc < grid[0].size() 
                    && grid[nr][nc] == 1){
                        q.push({nr, nc});
                        grid[nr][nc] = 0; // visit
                        res++;
                }
            }
        }
        return res;
    }
};
