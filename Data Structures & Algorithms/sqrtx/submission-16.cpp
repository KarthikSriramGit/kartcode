class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while(left <= right){
            int mid = left + (right - left)/2;
            long long square = (long long)mid * mid;
            if(square < x){
                left = mid + 1;
            }
            else if(square > x){
                right = mid - 1;
            }
            else{
                return mid;
            }
        }
        return right;
    }
};