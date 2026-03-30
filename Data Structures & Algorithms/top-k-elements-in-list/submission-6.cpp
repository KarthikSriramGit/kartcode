class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto& iter : mp){
            bucket[iter.second].push_back(iter.first);
        }
        vector<int> result;
        for(int i = bucket.size() - 1; i >= 0; i--){
            for(int n : bucket[i]){
                result.push_back(n);
                if(result.size() == k){
                    return result;
                }
            }      
        }
        return {};
    }
};
