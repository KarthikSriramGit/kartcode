class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int count = 0;
        for(int num : nums){
            if(num){
                count++;
            }
            else{
                count = 0;
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};