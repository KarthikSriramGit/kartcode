class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxval = 0;
        for(int num : nums){
            int count = 1;
            int i = num;
            if(!seen.count(i-1)){
                while(seen.count(i+1)){
                    count++;
                    i++;
                }
            }
            maxval = max(count,maxval);
        }
        return maxval;
    }
};
