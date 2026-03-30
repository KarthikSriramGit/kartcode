class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> res;
        int check = nums.size() / 3;
        for(int num : nums){
            freq[num]++;
        }
        for(auto& iter : freq){
            if(iter.second > check){
                res.push_back(iter.first);
            }
        }
        return res;
    }
};