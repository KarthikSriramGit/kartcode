class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int num : weights){
            sum += num;
        }
        int capacity = *max_element(weights.begin(), weights.end());
        while(capacity <= sum){
            int index = 0;
            int day = 1;
            int currSum = 0;
            while(index < weights.size()){
                currSum += weights[index];
                if(currSum <= capacity){
                    index++;
                }   
                else{
                    day++;
                    currSum = 0;
                }
            }
            if(day <= days){
                return capacity;
            }
            capacity++;
        }
        return sum;
    }
};