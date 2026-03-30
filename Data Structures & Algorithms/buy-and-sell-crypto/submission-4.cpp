class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxval = 0;
        int left = 0; 
        int right = 1;
        int profit = 0;
        while(right < prices.size()){
            if(prices[right] > prices[left]){
                profit = prices[right] - prices[left];
                maxval = max(profit, maxval);
            }
            else{
                left = right;
                profit = 0;
            }
            right++;
        }
        return maxval;
    }
};
