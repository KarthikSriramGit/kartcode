class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> count;
        for(int num : nums){
            count[num]++;
        }
        vector<int> res;
        for(auto& iter: count){
            for(int i = 0; i < iter.second; i++){
                res.push_back(iter.first);
            }
        }
        return res;
    }
};