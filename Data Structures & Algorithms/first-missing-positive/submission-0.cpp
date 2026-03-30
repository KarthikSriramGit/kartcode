class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> arr(nums.size(), false);
        for(int num : nums){
            if(num > 0 && num <= nums.size()){
                arr[num-1] = true;
            }
        }
        for(int i = 0; i < arr.size(); i++){
            if(!arr[i]){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};