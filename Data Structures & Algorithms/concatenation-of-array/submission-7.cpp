class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        uint32_t n = nums.size();
        vector<int> result(2 * n);
        for(size_t i = 0; i < n; i++){
            result[i] = nums[i];
            result[i + n] = nums[i];
        }
        return result;
    }
};