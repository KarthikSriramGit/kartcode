class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        k = k % nums.size();
        int left = nums.size() - k;
        while(left < nums.size()){
            temp.push_back(nums[left]);
            left++;
        }
        int right = nums.size() - k;
        for(int i = 0; i < right; i++){
            temp.push_back(nums[i]);
        }
        for(int i = 0; i < temp.size(); i++){
            nums[i] = temp[i];
        }
    }
};