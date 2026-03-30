class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int req = n / 3 ;
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        vector<int> res;
        for(auto& iter : freq){
            if(iter.second > req){
                res.push_back(iter.first);
            }
        }
        return res;
    }
};