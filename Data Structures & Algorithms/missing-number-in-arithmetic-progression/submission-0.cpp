class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int change = arr[1] - arr[0];
        for(int i = 0; i < arr.size() -1; i++){
            int curr_change = arr[i + 1] - arr[i];
            if (abs(curr_change) < abs(change)) change = curr_change;
        }
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i + 1] - arr[i] != change){
                return arr[i] + change; 
            }
        }
        return arr[0];
    }
};