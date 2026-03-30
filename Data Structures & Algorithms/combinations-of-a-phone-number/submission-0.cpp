class Solution {
public:
    vector<string> result;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", 
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        result.clear();
        if(digits.empty()) { return result;}  
        backtrack(digits,"",0);
        return result;
    }
    void backtrack(string digits, string s, int i){
        if(digits.size() == s.size()){
            result.push_back(s);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for(char c: chars){
            backtrack(digits, s + c, i+1);
        }
    }
};
