class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture[0].size();
        vector<vector<bool>> mask(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            bool black_flag = false;
            pair<int, int> indices = {};
            for(int j = 0; j < n; j++){
                if(picture[i][j] == 'B'){
                    if(black_flag == false){
                        black_flag = true;
                        indices = {i, j};
                    } else {
                        black_flag = false;
                        indices = {};
                        break;
                    }                
                }
            }
            if(black_flag) {
                int row = indices.first;
                int col = indices.second;
                mask[row][col] = true;
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            bool black_flag = false;
            pair<int, int> indices = {};
            for(int j = 0; j < m; j++){
                if(picture[j][i] == 'B'){
                    if(black_flag == false){
                        black_flag = true;
                        indices = {j, i};
                    } else {
                        black_flag = false;
                        indices = {};
                        break;
                    }                
                }
            }
            if(black_flag) {
                int row = indices.first;
                int col = indices.second;
                if(mask[row][col]) count++;
            }
        }
        return count;
    }
};
