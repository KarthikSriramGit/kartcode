class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counts(3, 0);
        for(int color : nums){
            counts[color]++;
        }
        nums.clear();
        for(int i = 0; i < counts.size(); i++){
            for(int j = 0; j < counts[i]; j++){
                nums.push_back(i);
            }
        }
    }
};