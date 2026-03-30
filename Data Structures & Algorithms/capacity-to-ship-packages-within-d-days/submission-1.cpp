class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int num : weights){
            sum += num;
        }
        int left = *max_element(weights.begin(), weights.end());
        int right = sum;
        while(left <= right){
            int mid = left + (right - left)/2;
            int index = 0;
            int day = 1;
            int currSum = 0;
            while(index < weights.size()){
                currSum += weights[index];
                if(currSum <= mid){
                    index++;
                }   
                else{
                    day++;
                    currSum = 0;
                }
            }
            if(day <= days){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};