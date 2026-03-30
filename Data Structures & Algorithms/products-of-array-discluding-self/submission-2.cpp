class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0, product = 1;
        for(int num : nums){
            if(num == 0){
                zeros++;
            }
            else{
                product *= num;
            }
        }
        vector<int> result;
        if(zeros > 1){
            result = vector<int>(nums.size(), 0);
            return result;
        }
        for(int num : nums){
            int val = 0;
            if(zeros == 1) {val = num == 0? product : 0;}
            else{
                val = product/num;
            }
            result.push_back(val);
        }
        return result;
    }
};
