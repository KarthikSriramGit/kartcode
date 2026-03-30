class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){ // l == r points to the min and would infinitely go
            int m = l + (r - l)/2;
            if(nums[m] < nums[r]){
                r = m; // you are in the Right portion, get to a mid point;
            }
            else{
                l = m + 1; // go to the Right portion
            }
        }
        return nums[l]; // min
    }
};
