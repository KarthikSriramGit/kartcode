class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeros_count = 0;
        for(int num : nums){
            if(num == 0){
                zeros_count++;
            }
            else{
                product *= num;
            }
        }
        vector<int> result;
        for(int num : nums){
            if(zeros_count > 1){
                result.push_back(0);
            }
            else if(zeros_count == 1){
                result.push_back(num == 0 ? product : 0);
            }
            else{
                result.push_back(product/num);            
            }
        }
        return result;
    }
};