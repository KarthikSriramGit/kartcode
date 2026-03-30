class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixsum;
        int res = 0, sum = 0;
        prefixsum[0] = 1;
        for(int num : nums){
            sum += num;
            if(prefixsum.count(sum -k)){
                res += prefixsum[sum - k];
            }
            prefixsum[sum]++;
        }
        return res;
    }
};