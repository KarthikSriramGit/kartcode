class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        vector<vector<string>> result;
        for(const string& s : strs){
            string sorted_string = s;
            sort(sorted_string.begin(), sorted_string.end());
            dict[sorted_string].push_back(s);
        }
        for(auto& iter: dict){
            result.push_back(iter.second);
        }
        return result;
    }
};
