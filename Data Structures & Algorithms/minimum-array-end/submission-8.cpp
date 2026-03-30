class Solution {
public:
    long long minEnd(int n, int x) {
        long long curr = x;
        int iter = n - 1;
        while(iter){
            curr = curr + 1 | x;
            iter--;
        }
        return (long long)curr;
    }
};