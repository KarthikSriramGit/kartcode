class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int num : nums){
            xorr ^= num;
        }
        int diff_bit = 1;
        while((xorr & diff_bit) == 0){
            diff_bit <<= 1;
        }
        int a = 0, b = 0;
        for(int& num : nums){
            if(num & diff_bit){
                a ^= num;
            }
            else{
                b ^= num;
            }
        }
        return {a, b};
    }
};