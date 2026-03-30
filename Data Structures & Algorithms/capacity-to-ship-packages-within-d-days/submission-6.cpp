class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while(l <= r){
            int m = l + (r - l)/2;
            int index = 0;
            int currSum = 0;
            int d = 1;
            while(index < weights.size()){
                currSum += weights[index];
                if(currSum <= m){
                    index++;
                }
                else{
                    d++;
                    currSum = 0;
                }
            }
            if(d <= days){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};