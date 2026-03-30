class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i <=n ; i++){
            result.push_back(number1bits(i));
        }
        return result;
    }
    int number1bits(int n){
        int count = 0;
        while(n){
            n &= n - 1;
            count++;
        }
        return count;
    }
};
