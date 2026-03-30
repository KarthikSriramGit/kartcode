class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();
        sort(nums.begin(), nums.end());
        backtrack(nums, target, {}, 0, 0);
        return res;
    }
    void backtrack(vector<int>& nums, int target, vector<int> curr, int sum, int i){
        if(sum == target){
            res.push_back(curr);
            return;
        }
        for(int j = i; j < nums.size(); j++){
            if (sum + nums[j] > target) {
                return;
            }
            curr.push_back(nums[j]);
            backtrack(nums, target, curr, sum + nums[j], j);
            curr.pop_back();
        }
    }
};
