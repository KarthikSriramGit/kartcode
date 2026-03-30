class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        result.clear();
        backtrack(s, {}, result, 0);
        return result;
    }
    void backtrack(string s, vector<string> subset, vector<vector<string>>& result, int i){
        if(i >= s.length()){
            result.push_back(subset);
            return;
        }
        for(int j = i; j < s.length(); j++){
            if(isPalindrome(s, i, j)){
                subset.push_back(s.substr(i, j-i +1));
                backtrack(s, subset, result, j + 1);
                subset.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int left, int right){
        if(s.length() == 1){ return true;}
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true; 
    }
};
