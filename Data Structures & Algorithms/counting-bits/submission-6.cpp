class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++){
            res.push_back(hammingWeight(i));
        }
        return res;
    }
    int hammingWeight(int n){
        int count = 0;
        while(n){
            n &= n - 1;
            count++;
        }
        return count;
    }
};
