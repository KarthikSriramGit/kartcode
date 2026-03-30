class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> mp(3);
        for(int num : nums){
            mp[num]++;
        }
        int index = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < mp[i]; j++){
                nums[index++] = i;
            }
        }
    }
};