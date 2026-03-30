class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            if(r - l > k){
                seen.erase(nums[l]);
                l++;
            }
            if(seen.find(nums[r]) != seen.end()){
                return true;
            }
            seen.insert(nums[r]);
        }
        return false;
    }
};