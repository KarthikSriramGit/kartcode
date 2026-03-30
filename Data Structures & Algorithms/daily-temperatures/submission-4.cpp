class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> temps; // {temp, index}
        vector<int> result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!temps.empty() && temperatures[i] > temps.top().first){
                auto pair = temps.top(); temps.pop();
                result[pair.second] = i - pair.second;
            }
            temps.push({temperatures[i], i});
        }
        return result;
    }
};
