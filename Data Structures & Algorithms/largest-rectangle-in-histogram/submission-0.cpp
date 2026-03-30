class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        for(int i = 0; i < heights.size(); i++){
            int h = heights[i];
            int width = 1;
            // Check bars to the right
            for(int j = i + 1; j < heights.size(); j++){
                if(heights[j] >= h) width++;
                else break;
            }
            // Check bars to the left
            for(int j = i - 1; j >= 0; j--){
                if(heights[j] >= h) width++;
                else break;
            }
            int area = h * width;
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }
};