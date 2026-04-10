class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count_zeros = 0;
        int product = 1;
        for(int num : nums){
            if(num == 0){
                count_zeros++;
            }
            else{
                product *= num;
            }
        }
        if (count_zeros > 1) {
            return vector<int>(nums.size(), 0);
        }
        vector<int> res;
        for(int num : nums){
            if(num == 0){
                res.push_back(product);
            }
            else if (count_zeros == 1) {
                res.push_back(0);
            }
            else{
                res.push_back(product/num);
            }
        }
        return res;
    }
};