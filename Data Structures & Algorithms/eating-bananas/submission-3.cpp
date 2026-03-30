class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 1;
        int maxval = INT_MIN;
        for(int num : piles){
            maxval = max(num, maxval);
        }
        while(k <= maxval){
            long long hours = 0;
            for(int num : piles){
                if(num < k){
                    hours++;
                }
                else{
                    hours += (num % k == 0) ? (num / k) : (num / k + 1);
                }
            }
            if(hours <= h) return k;
            k++;
        }
        return maxval;
    }
};
