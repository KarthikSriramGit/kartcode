class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for(char c : s){
            freq[c]++;
        }
        int maxOdd = 0;
        int minEven = INT_MAX;
        for(auto& iter: freq){
            if(iter.second % 2 != 0){
                maxOdd = max(maxOdd, iter.second);
            }
            else{
                minEven = min(minEven, iter.second);
            }
        }
        return maxOdd - minEven;
    }
};