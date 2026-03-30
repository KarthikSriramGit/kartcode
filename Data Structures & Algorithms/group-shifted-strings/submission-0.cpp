class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for(string s : strings) {
            string key = "";
            for(int i = 1; i < s.length(); i++) {
                int diff = (s[i] - s[i-1] + 26) % 26;
                key += to_string(diff) + ",";
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& iter : mp){
            result.push_back(iter.second);
        }
        return result;
    }
};