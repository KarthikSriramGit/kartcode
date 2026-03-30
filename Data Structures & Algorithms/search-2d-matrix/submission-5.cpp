class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size(); 
        int COLS = matrix[0].size();
        int top = 0;
        int bot = ROWS - 1;
        int row = 0;
        while(top <= bot){ // O(log m)
            row = top + (bot - top)/2;
            if(target > matrix[row][COLS - 1]){
                top = row + 1;
            }
            else if(target < matrix[row][0]){
                bot = row - 1;
            }
            else{
                break;
            }
        }
        if(top > bot) return false;
        row = top + (bot - top)/2;
        int left = 0;
        int right = COLS - 1;
        while(left <= right){ // O(log n)
            int mid = left + (right - left)/2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return false;
    }
};
