class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int l = 0; l < nums.size(); l++){
            for(int r = l + 1; r < min(int(nums.size()), l + k + 1); r++){
                if(nums[l] == nums[r]){
                    return true;
                }
            }
        }
        return false;        
    }
};