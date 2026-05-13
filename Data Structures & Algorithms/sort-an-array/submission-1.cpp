class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> freq;
        for(const int num : nums){
            freq[num]++;
        }
        vector<int> result;
        for(auto& iter: freq){
            for(int i = 0; i < iter.second; i++){
                result.push_back(iter.first);
            }
        }
        return result;
    }
};