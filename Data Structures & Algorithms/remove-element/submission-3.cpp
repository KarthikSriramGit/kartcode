class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for(const int num : nums){
            if(num != val){
                temp.push_back(num);
            }
        }
        nums.clear();
        for(int num : temp){
            nums.push_back(num);
        }
        return nums.size();
    }
};