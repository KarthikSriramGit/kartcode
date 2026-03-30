class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while(left <= right){
            int k = left + (right - left)/2;
            int hours = 0;
            for(int pile : piles){
                hours += pile % k == 0? pile/k : pile/k + 1;
            }
            if(hours > h){
                left = k + 1;
            }
            else{
                right = k - 1;
            }
        }
        return left;
    }
};
