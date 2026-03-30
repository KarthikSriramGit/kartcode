class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3,0);
        for(int num : nums){
            freq[num]++;
        }
        nums.clear();
        for(int i = 0; i < 3; i++){
            for(int j = 0 ; j < freq[i]; j++){
                nums.push_back(i);
            }
        }
    }
};