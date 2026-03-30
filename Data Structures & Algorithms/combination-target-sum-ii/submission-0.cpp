class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        dfs(candidates,target, {},0, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, vector<int> curr, int total, int i){
        if(total == target){
            res.push_back(curr);
            return;
        }
        for(int j = i; j < candidates.size();j++){
            if(j > i && candidates[j] == candidates[j-1]){
                continue;
            }
            if(total + candidates[j] > target){
                break;
            }
            curr.push_back(candidates[j]);
            dfs(candidates,target, curr, total + candidates[j],j + 1);
            curr.pop_back();
        }
    }

};
