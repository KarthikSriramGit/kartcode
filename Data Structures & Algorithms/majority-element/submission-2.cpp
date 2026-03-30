class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int num : nums){
            count[num]++;
        }
        int res = 0;
        for(auto& iter : count){
            if(iter.second > count[res]){
                res = iter.first;
            }
        }
        return res;
    }
};