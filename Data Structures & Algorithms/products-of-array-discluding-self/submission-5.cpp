class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count_zeros = 0, totalProd = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                count_zeros++;
            }
            else{
                totalProd *= nums[i];
            }
        }
        if(count_zeros > 1){
            vector<int> res(nums.size(), 0);
            return res;   
        }
        vector<int> output(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(count_zeros == 1){
                if(nums[i] == 0){
                    output[i] = totalProd;
                }
                else{
                    output[i] = 0;
                }
            }
            else{
                output[i] = totalProd/nums[i];
            }
        }
        return output;
    }
};
