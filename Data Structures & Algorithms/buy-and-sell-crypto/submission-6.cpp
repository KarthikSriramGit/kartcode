class Solution {
public:
    int maxProfit(vector<int>& prices){
	int maxP = 0;
	int left = 0;
	for(int right = 1; right < prices.size(); right++){
        if(prices[right] > prices[left]){
                int profit = prices[right] - prices[left];
                maxP = max(profit, maxP);
            }
            else{
                left = right;
            }
        }
        return maxP;
    }

};
