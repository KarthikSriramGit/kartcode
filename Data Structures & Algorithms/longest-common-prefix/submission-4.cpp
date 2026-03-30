class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; i < strs[0].length(); i++){
            for(const string& s : strs){
                if(strs[0][i] != s[i] || i == s.length()){
                    return s.substr(0, i);
                }
            }
        }
        return strs[0];
    }
};