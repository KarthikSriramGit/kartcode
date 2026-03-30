class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pair;
        for(int i = 0; i < position.size(); i++){
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<double> steps;
        for(auto& p : pair){
            steps.push_back((double)(target - p.first) / p.second); // steps
            if(steps.size() >= 2 && steps[steps.size() - 1] <= steps[steps.size() - 2]){
                steps.pop_back();
            }
        }
        return steps.size();
    }
};

// [7, 4, 1, 0]
// [1, 2, 2, 1]
// [3, 4.5, 10]
