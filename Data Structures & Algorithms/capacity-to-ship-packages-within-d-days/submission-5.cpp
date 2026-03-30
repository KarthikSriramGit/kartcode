class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days){
	int left = *max_element(weights.begin(), weights.end());
    int right  = 0;
    for(int num : weights){
        right += num;
    }
    while(left <= right){
        int capacity = left + (right - left)/2;
        int currDays = 1;
    int index = 0;
    int currSum = 0;
    while(index < weights.size()){
        currSum += weights[index];
        if(currSum <= capacity){
            index++;
        }
        else{
            currDays++;
            currSum = 0;
        }
    }
    if(currDays > days){
        left = capacity + 1;
    }
    else{
        right = capacity - 1;
    }
    }
    return left;
}

};