class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0},{0, 1}, {0, -1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        vector<vector<int>> indegree(ROWS, vector<int>(COLS, 0));
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                for(int i = 0; i < 4; i++){
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];
                    if(nr >= 0 && nr < ROWS &&
                        nc >= 0 && nc < COLS &&
                        matrix[nr][nc] < matrix[r][c]){
                            indegree[r][c]++;
                    }
                }
            }
        }
        queue<pair<int, int>> q;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(indegree[r][c] == 0){
                    q.push({r, c});
                }
            }
        }
        int layers = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto[r, c] = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];
                    if(nr >= 0 && nr < ROWS &&
                        nc >= 0 && nc < COLS &&
                        matrix[nr][nc] > matrix[r][c]){
                            indegree[nr][nc]--;
                            if(indegree[nr][nc] == 0){
                                q.push({nr, nc});
                            }
                    }
                }
            }
            layers++; 
        }
        return layers;
    }
};
