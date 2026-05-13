class Solution {
public:
    void sortColors(vector<int>& nums) {
        array<int, 3> colors{};
        for(const int num : nums){
            colors[num]++;
        }
        int index = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < colors[i]; j++){
                nums[index++] = i;
            }
        }
    }
};