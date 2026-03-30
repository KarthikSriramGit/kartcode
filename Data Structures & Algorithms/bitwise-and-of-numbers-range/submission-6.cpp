class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = left;
        for(int i = left + 1; i <= right; i++){
            result &= i;
        }
        return result;
    }
};