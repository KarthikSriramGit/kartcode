class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while(left <= right){
            int mid = left + (right - left)/2;
            if(canSplit(nums, k, mid)){
                right  = mid - 1;
            }
            else{
                left = mid + 1; 
            }
        }
        return left;
    }
    bool canSplit(vector<int>& nums, int k, int largest){
        int subarray = 1, currSum = 0;
        for(int num : nums){
            currSum += num;
            if(currSum > largest){
                subarray++;
                if(subarray > k){
                    return false;
                }
                currSum = num;
            }
        }
        return true;
    }
};