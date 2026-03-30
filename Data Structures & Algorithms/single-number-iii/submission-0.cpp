class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int num : nums){
            xorr ^= num;
        }
        int diff_bit = 1;
        while((xorr & diff_bit) == 0){ // find the first position in xorr which is a 1;
            diff_bit <<= 1;
        }

        // Partition array
        int a = 0, b = 0;
        for(int num : nums){
            if(num & diff_bit){ // if same bit is set
                a ^= num; // partition as one number
            }
            else{
                b ^= num; // partition as the other number
            }
        }
        return {a, b};
    }
};