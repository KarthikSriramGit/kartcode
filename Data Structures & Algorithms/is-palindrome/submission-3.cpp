class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() -1 ;
        while(left < right){
            while (left < right && !isalphaNum(s[left])){ left++;}
            while (left < right && !isalphaNum(s[right])){ right--;}
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool isalphaNum(char c){
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9');
    }
};
