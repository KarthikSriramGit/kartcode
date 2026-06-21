class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(const int &num : nums){
            xorr ^= num;
        }
        return xorr;
    }
};
