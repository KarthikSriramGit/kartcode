class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;
        for(int num : piles){
            right = max(num, right);
        }
        int k = 0;
        while(left <= right){
            k = left + (right - left)/2;
            long long hours = 0;
            for(int num : piles){
                hours += (num % k == 0) ? (num / k) : (num / k + 1);
            }
            if(hours <= h){
                right = k - 1;
            }
            else{
                left = k + 1;
            }
        }
        return left;
    }
};
