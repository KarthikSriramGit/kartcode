class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int present = 0;
        int future = 1;
        int maxTrade = 0;
        while(future < prices.size()){
            if(prices[present] < prices[future]){
                int trade = prices[future] - prices[present];
                maxTrade = max(trade, maxTrade);
            }
            else{
                present = future;
            }
            future++;
        }
        return maxTrade;
    }
};
