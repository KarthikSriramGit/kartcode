class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(const int num : nums){
            freq[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto& iter : freq){
            bucket[iter.second].push_back(iter.first);
        }
        vector<int> result;
        for(int i = bucket.size() - 1; i >= 0; i--){
            for(int j = bucket[i].size() - 1; j >= 0; j--){
                result.push_back(bucket[i][j]);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};
