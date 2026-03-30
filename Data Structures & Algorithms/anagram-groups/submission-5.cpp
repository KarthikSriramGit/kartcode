class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(const string& s : strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(s);
        }
        vector<vector<string>> res;
        for(auto& iter : mp){
            res.push_back(iter.second);
        }
        return res;
    }
};
