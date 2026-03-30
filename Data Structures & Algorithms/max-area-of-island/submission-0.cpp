class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_val = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    max_val = max(max_val, bfs(grid, r , c));
                }
            }
        }
        return max_val;
    }
    int bfs(vector<vector<int>>& grid, int r, int c){
        queue<pair<int,int>> q;
        grid[r][c] = 0;
        q.push({r,c});
        int area = 1;
        while(!q.empty()){
            auto[row,col] = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int next_r = row + directions[i][0];
                int next_c = col + directions[i][1];
                if(next_r < grid.size() && next_c < grid[0].size() && next_r >= 0 && next_c >= 0 && grid[next_r][next_c] == 1){
                    area++;
                    grid[next_r][next_c] = 0;
                    q.push({next_r, next_c});
                }
            }
        }
        return area;
    }
};
