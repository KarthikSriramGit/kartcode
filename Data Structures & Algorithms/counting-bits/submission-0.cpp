class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i =0; i <= n; i++){
            int count = 0;
            int x = i;
            while(x){
                x &= (x-1); // Kernighan's Algorithm
                count++;
            }
            result.push_back(count);
        }   
    return result;
    }
};
