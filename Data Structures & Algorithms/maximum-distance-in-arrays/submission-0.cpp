class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxdistance = 0;
        for(int i = 0; i < arrays.size() - 1; i++){
            for(int j = i + 1; j < arrays.size(); j++){
                for(int a : arrays[i]){
                    for(int b : arrays[j]){
                        int distance = abs(a - b);
                        maxdistance = max(distance, maxdistance);
                    }
                }
            }
        }
        return maxdistance;
    }
};
