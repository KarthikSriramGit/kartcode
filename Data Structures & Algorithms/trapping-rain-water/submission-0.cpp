class Solution {
public:
    int trap(vector<int>& heights) {
        int left = 0, right = heights.size()-1, leftmax = heights[left], rightmax = heights[right];
        int result = 0;
        while(left < right){
            if(leftmax < rightmax){
                left++;
                leftmax = max(leftmax, heights[left]);
                result += leftmax - heights[left];
            }
            else{
                right--;
                rightmax = max(rightmax,heights[right]);
                result += rightmax - heights[right];
            }
        }
        return result;  
    }
};
