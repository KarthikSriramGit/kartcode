class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int min_val = nums[0];
        while(left <= right){
            if (nums[left] < nums[right]){
                min_val = min(min_val, nums[left]);
                break;
            }
            int mid = left + (right-left)/2;
            min_val = min(min_val, nums[mid]);
            if(nums[mid] >= nums[left]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return min_val;
    }
};
