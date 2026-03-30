class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while(left < right){
            while(left < right && !alphanum(s[left])) left++;
            while(left < right && !alphanum(s[right])) right--;
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool alphanum(char c){
        return (c >= 'A' && c <= 'Z') || 
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9');
    }
};
