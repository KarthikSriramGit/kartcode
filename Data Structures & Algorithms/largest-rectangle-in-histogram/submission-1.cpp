class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<pair<int,int>> s;
        s.push({-1, 0});
        int maxarea = 0;
        for(int i = 0; i < heights.size(); i++){
            while(!s.empty() && heights[i] < s.top().second){
                int h = s.top().second;
                s.pop();
                int width = (i - s.top().first - 1);
                maxarea = max(maxarea, h * width);
            }
            s.push({i, heights[i]});
        }
        return maxarea;
    }
};