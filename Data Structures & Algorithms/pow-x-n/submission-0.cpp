class Solution {
public:
    double myPow(double x, int n) {
        double pow = 1;
        if(x == 0 && n > 1) {return 0;}
        if(x == 1 || n==0){ return 1;}
        for(int i = 0; i < abs(n) ; i++){
                pow *= x;
        }
        return n>=0? pow: 1/pow;
    }
};
