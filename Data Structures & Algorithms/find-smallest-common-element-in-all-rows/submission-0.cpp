class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int, int> freq;
        for(vector<int>& vec : mat){
            for(int num : vec){
                freq[num]++;
                if(freq[num] == mat.size()){
                    return num;
                }
            }
        }
    }
};
