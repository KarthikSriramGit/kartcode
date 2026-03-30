class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int,int>> stck; // pair: {temp, index}
        for(int i = 0; i < temperatures.size(); i++){
            while(!stck.empty() && temperatures[i] > stck.top().first){
                auto pair = stck.top();
                stck.pop();
                result[pair.second] = i - pair.second;
            }
            stck.push({temperatures[i], i});
        }
        return result;
    }
};
