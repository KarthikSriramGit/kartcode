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
        for(int i = 0; i < nums.size()- k; i++){
            temp.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = temp[i];
        }
        temp.clear();
    }
};