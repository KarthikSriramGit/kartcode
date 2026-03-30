class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(),nums.end());
        int maxCount = 0;
        for(int num : seen){
            if(!seen.count(num - 1)){
                int i = num;
                int count = 0;
                while(seen.count(i)){
                    count++;
                    i++;
                }
                maxCount = max(maxCount, count);
            }

        }
        return maxCount;
    }
};
