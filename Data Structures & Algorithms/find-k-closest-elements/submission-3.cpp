class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            int point = 0;
            for(int i = 1; i < arr.size(); i++){
                if(abs(arr[i] - x) < abs(arr[point] - x)){
                    point = i;
                }
            }
            
            int left = point;
            int right = point;
            while(right - left + 1 < k){
                if (left == 0) right++;
                else if (right == arr.size() - 1) left--;
                else {
                    int a = arr[left - 1];
                    int b = arr[right + 1];
                    if(abs(a - x) <= abs(b - x)){
                        left--;
                    }
                    else{
                        right++;
                    }
                }
            }
            vector<int> result;
            for(int i = left; i <= right; i++){
                result.push_back(arr[i]);
            }
            return result;
        }
};