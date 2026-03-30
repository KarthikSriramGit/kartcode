class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;
        while(r - l + 1 > k){
            int a = arr[l];
            int b = arr[r];
            if(abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b)){
                r--;
            }
            else{
                l++;
            }
        }
        vector<int> res;
        for(int i = l; i <= r; i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};