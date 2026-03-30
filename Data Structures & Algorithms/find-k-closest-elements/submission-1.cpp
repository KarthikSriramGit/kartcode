class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;
        while(right - left + 1 > k){
            int a = arr[left];
            int b = arr[right];
            if((abs(a - x) < abs(b-x)) || (abs(a-x) == abs(b-x) && a < b)){
                right--;
            }
            else{
                left++;
            }
        }
        vector<int> result;
        for(int i = left; i <= right; i++){
            result.push_back(arr[i]);
        }
        return result;
    }
};