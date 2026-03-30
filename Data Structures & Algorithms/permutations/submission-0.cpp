class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        backtrack(nums, 0);
        return res;
    }
    void backtrack(vector<int>& nums, int i){
        if(i == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int j = i; j  < nums.size(); j++){
            swap(nums[j],nums[i]);
            backtrack(nums, i+1);
            swap(nums[i],nums[j]);
        }
    }   
    
};
