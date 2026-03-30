class Solution {
public:
    string longestPalindrome(string s) {
        int i = 0;
        string maxRes = "";
        int maxLen = 0;

        while(i < s.length()) {
            int j = i - 1;
            int k = i + 1;

            // Expand over repeated characters on the right
            while(k < s.length() && s[k] == s[i]){
                k++;
            }

            // Save this center to skip later
            int centerEnd = k;

            // Expand around center (j, k)
            while(j >= 0 && k < s.length() && s[j] == s[k]){
                j--;
                k++;
            }

            // Check if this palindrome is longer
            if(k - j - 1 > maxLen){
                maxLen = k - j - 1;
                maxRes = s.substr(j + 1, maxLen);
            }

            i = centerEnd;  // Move to next distinct center
        }

        return maxRes;
    }
};
