class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int top = 0, bottom = matrix.size(); // rows
        int left = 0, right = matrix[0].size(); // columns

        while (left < right && top < bottom) {
            for (int i = left; i < right; i++) { // move along the column
                res.push_back(matrix[top][i]); 
            }
            top++; // move down to the next row as first top is done, right is at the edge
            for (int i = top; i < bottom; i++) { // move along the row till the bottom
                res.push_back(matrix[i][right - 1]);
            }
            right--; // move back to the previous column
            if (!(left < right && top < bottom)) { 
                break;
            }
            for (int i = right - 1; i >= left; i--) { // move along the columns in reverse
                res.push_back(matrix[bottom - 1][i]);
            }
            bottom--; 
            for (int i = bottom - 1; i >= top; i--) { // move up by the row till top which is at next row
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
};