class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l <= r){
            int k = l + (r - l)/2;
            long long hours =  0;
            for(int i : piles){
                hours += i % k == 0 ? i/k : i/k  + 1;  
            }
            if(hours <= h){
                r = k - 1;
            }
            else{
                l = k + 1;
            }
        }
        return l;
    }
};
