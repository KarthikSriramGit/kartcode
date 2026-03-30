class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, {}, 0);
        return res;
    }
    void backtrack(vector<int>& arr, vector<int> curr, int i){
        res.push_back(curr);
        for(int j = i; j < arr.size(); j++){
            curr.push_back(arr[j]);
            backtrack(arr, curr, j+1);
            curr.pop_back();
        }
    }
};
