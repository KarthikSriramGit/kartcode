class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int index = 0;
        while(index < nums.size()){
            int left = index + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[index] + nums[left] + nums[right]; 
                if(sum == 0){
                    result.push_back({nums[index], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }
                else if( sum > 0){
                    right--;
                }
                else{
                    left++;
                }

            }
            index++;
            while (index < nums.size() && nums[index] == nums[index - 1]) index++;
        }
        return result;
    }
};
