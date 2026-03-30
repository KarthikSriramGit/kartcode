class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int max = 0;
        for(int num : nums){
            if(num > max){
                max = num;
            }
        }
        for(int i = 1; i < max; i++){
            if(seen.find(i) == seen.end()){
                return i;
            }
        }
        return max + 1;
    }
};