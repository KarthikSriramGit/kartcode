class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int num : arr){
            freq[num]++;
        }
        int maxVal = 0;
        for(auto& iter: freq){
            if(iter.first == iter.second){
                maxVal = max(iter.first, maxVal);
            }
        }
        if(maxVal == 0){
            return -1;
        }
        return maxVal;
    }
};