class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxCount = 0;
        for(int num : nums){
            int i = num;
            int count = 0;
            while(seen.count(i)){
                i++;
                count++;
            }
            maxCount  = max(count, maxCount);
        }
        return maxCount;
    }
};
