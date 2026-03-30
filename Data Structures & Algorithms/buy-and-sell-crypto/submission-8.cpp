class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = 0;
        int l = 0;
        for(int r = 1; r < prices.size(); r++){
            if(prices[r] > prices[l]){
                int profit = prices[r] - prices[l];
                maxprof = max(profit, maxprof);
            }
            else{
                l = r;
            }
        }
        return maxprof;
    }
};
