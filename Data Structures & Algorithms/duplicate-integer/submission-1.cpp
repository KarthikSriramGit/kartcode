class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> check;
        for(int i : nums){
            if(check.count(i)){
                return true;
            }
            check.insert(i);
        }
        return false;
    }
};