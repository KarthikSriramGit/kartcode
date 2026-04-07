class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t tmp = n;
        int count = 0;
        while(tmp){
            tmp &= tmp - 1;
            count++;
        }
        return count;
    }
};
