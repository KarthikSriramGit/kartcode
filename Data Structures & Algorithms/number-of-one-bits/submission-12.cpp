class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t count = 0;
        uint32_t temp = n;
        while(temp){
            temp &= temp - 1;
            count++;
        }
        return count;
    }
};
