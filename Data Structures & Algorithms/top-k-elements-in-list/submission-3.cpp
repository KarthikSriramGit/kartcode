class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int maxFreq = 0;
        for (auto& iter : freq) {
            maxFreq = max(maxFreq, iter.second);
        }

        vector<vector<int>> bucket(maxFreq + 1);
        for (auto& iter : freq) {
            bucket[iter.second].push_back(iter.first);
        }

        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};
