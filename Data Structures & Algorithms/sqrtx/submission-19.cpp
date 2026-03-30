class Solution {
public:
    int mySqrt(int x) {
        int l = 0; 
        int r = x;
        if(x == 0) return 0;
        if(x == 1) return 1;
        while(l <= r){
            int m = l + (r - l)/2;
            long long sq = (long long)m * m;
            if(sq > x){
                r = m - 1;
            }
            else if(sq < x){
                l = m  + 1;
            }
            else{
                return m;
            }
        }
        return r;
    }
};