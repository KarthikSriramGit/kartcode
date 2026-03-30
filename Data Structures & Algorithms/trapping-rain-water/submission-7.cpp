class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0; 
        int right = height.size() - 1; 
        int res = 0;
        int leftmax = height[left];
        int rightmax = height[right];
        while(left < right){
            if(leftmax < rightmax){
                left++;
                leftmax = max(height[left], leftmax);
                res += leftmax - height[left];
            }
            else{
                right--;
                rightmax = max(height[right], rightmax);
                res+= rightmax - height[right];
            }
        }
        return res;
    }
};
