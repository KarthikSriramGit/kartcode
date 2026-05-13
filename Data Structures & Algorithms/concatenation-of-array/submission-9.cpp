class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result(2 * nums.size());
        for(size_t i = 0; i < nums.size(); i++){
            result[i] = nums[i];
            result[i + nums.size()] = nums[i];
        }
        return result;
    }
};