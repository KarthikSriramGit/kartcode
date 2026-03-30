class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; i < strs[0].length(); i++){
            for(const string& s : strs){
                if(s[i] != strs[0][i] || i == s.length()){
                    return s.substr(0, i);
                }
            }
        }
        return strs[0];
    }
};