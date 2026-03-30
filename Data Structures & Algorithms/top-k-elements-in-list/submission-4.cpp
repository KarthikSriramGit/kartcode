class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> seen;
        for(int num : nums){
            seen[num]++;
        }
        vector<vector<int>> bubble(nums.size() + 1);
        for(auto& iter : seen){
            bubble[iter.second].push_back(iter.first);
        }
        for(int i = bubble.size() - 1; i > 0; i--){
            for(int n : bubble[i]){
                result.push_back(n);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return {};
    }
};
