class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int maxprof = 0;
        for(int r = 1; r < prices.size(); r++){
            if(prices[r] > prices[l]){
                int prof = prices[r] - prices[l];
                maxprof = max(prof, maxprof);
            }
            else{
                l = r;
            }
        }
        return maxprof;        
    }
};
