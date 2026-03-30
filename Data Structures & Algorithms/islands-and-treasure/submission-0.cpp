class Solution {
public:
    int INF = INT_MAX;
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 0){
                    q.push({r,c});
                }
            }
        }
        while(!q.empty()){
            auto[r, c] = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int next_r = r + directions[i][0];
                int next_c = c + directions[i][1];
                if(next_r >= 0 && next_r < grid.size() && next_c >=0 && next_c < grid[0].size() 
                    && grid[next_r][next_c] == INF){
                        grid[next_r][next_c] = grid[r][c] + 1;
                        q.push({next_r,next_c});
                    }
            }
        }
    }
};
