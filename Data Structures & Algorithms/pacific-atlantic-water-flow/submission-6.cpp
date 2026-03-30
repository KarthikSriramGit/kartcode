class Solution {
public:
    int directions[4][2] = {{1 , 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size(); 
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        queue<pair<int,int>> pacQueue;
        queue<pair<int,int>> atlQueue;
        for(int r = 0; r < ROWS; r++){
            pacQueue.push({r, 0});
            atlQueue.push({r, COLS-1});
        }
        for(int c = 0; c < COLS; c++){
            pacQueue.push({0, c});
            atlQueue.push({ROWS-1, c});
        }
        bfs(pacQueue, pac, heights);
        bfs(atlQueue, atl, heights);
        vector<vector<int>> res;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(pac[r][c] && atl[r][c]){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& grid){
        while(!q.empty()){
            auto[r, c] = q.front(); q.pop();
            ocean[r][c] = true;
            for(int i = 0; i < 4; i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if(nr >= 0 && nr < grid.size() && nc >=0 && nc < grid[0].size() && !ocean[nr][nc] && grid[nr][nc] >= grid[r][c]){
                    ocean[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
};
