class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int res = 0;
        int leftMax = height[left];
        int rightMax = height[right];
        while(left < right){
            if(leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                res += leftMax - height[left];
            }
            else{
                right--;
                rightMax = max(rightMax, height[right]);
                res += rightMax - height[right];
            }
        }
        return res;
    }
};
