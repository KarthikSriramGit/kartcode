class Solution {
public: 
    int fresh = 0;
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    fresh++;
                }
                if(grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }
        return bfs(grid, q);
    }

    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q){
        int time = 0;
        while(!q.empty() && fresh > 0){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto[row, col] = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int next_row = row + directions[i][0];
                    int next_col = col + directions[i][1];
                    if(next_row >= 0 && next_col >= 0 && next_row < grid.size() && next_col < grid[0].size() &&
                        grid[next_row][next_col] == 1){
                            grid[next_row][next_col] = 2;
                            q.push({next_row, next_col});
                            fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
