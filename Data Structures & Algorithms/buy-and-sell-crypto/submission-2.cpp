class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxval = 0;
        int left = 0; 
        int right = 1;
        int profit = 0;
        while(right < prices.size()){
            if(prices[right] >= prices[left]){
                profit += prices[right] - prices[right-1];
                maxval = max(profit, maxval);
            }
            else{
                profit = 0;
                left = right;
            }
            right++;
        }
        return maxval;
    }
};
