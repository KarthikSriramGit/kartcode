class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = 0;
        vector<int> res;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] >= x){
                pos = i;
                break;
            }
            pos = i;
        }

        int a = pos - 1, b = pos;
        while(k > 0){
            if (a >= 0 && b < arr.size()) {
                if (abs(arr[a] - x) <= abs(arr[b] - x)) {
                    res.push_back(arr[a--]);
                } else {
                    res.push_back(arr[b++]);
                }
            } else if (a >= 0) {
                res.push_back(arr[a--]);
            } else {
                res.push_back(arr[b++]);
            }
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};