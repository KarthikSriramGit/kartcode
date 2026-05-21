class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void bfs(vector<vector<char>>& grid, int row, int col){
        queue<pair<int,int>> q;
        grid[row][col] = '0';
        q.push({row, col});
        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if(nr >= 0 && nr < grid.size() && 
                    nc >= 0 && nc < grid[0].size() &&
                    grid[nr][nc] == '1'){
                        q.push({nr, nc});
                        grid[nr][nc] = '0';
                    }
            }
        }
    }
};
