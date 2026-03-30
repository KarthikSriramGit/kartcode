class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        if(s.length() != t.length()){
            return false;
        }
        else{
            for (int i = 0; i < s.length(); i++) {
            s_map[s[i]]++;
            t_map[t[i]]++;
            }
            for (auto iter = s_map.begin(); iter != s_map.end(); ++iter) {
                if (s_map[iter->first] != t_map[iter->first]) {
                    return false;
                }
            }
        }
        return true;
    }
};
