class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        while(i < nums.size() - 3){
            int j = i + 1;
            while(j < nums.size()){
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right){
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }
                else if(sum < target){
                    left++;
                }
                else{
                    right--;
                }
                }

                while(j < nums.size() - 2 && nums[j] == nums[j + 1]) j++;
                j++;
            }
            while(i < nums.size() - 3  && nums[i] == nums[i + 1]) i++;
            i++;
        }
        return result;
    }
};