class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> complement;
        for(int i =0; i < nums.size(); i++){
            if(complement.find(nums[i])!=complement.end()){
                result.push_back(complement[nums[i]]);
                result.push_back(i);
            }
            else{
                complement[target-nums[i]] = i;
            }
        }
        return result;
    }
};
