class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }   
        while(fresh > 0 && !q.empty()){
            int length = q.size();
            for(int i = 0; i < length; i++){
                auto[r , c] = q.front(); q.pop();
                for(int j = 0; j < 4; j++){
                    int nr = r + directions[j][0];
                    int nc = c + directions[j][1];
                    if(nr >= 0 && nr < grid.size() &&
                       nc >= 0 && nc < grid[0].size() &&
                       grid[nr][nc] == 1){
                            grid[nr][nc] = 2;
                            q.push({nr, nc});
                            fresh--;
                    } 
                } 
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
