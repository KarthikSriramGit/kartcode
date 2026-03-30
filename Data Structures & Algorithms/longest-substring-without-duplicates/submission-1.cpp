class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int res = 0;
        int right = 0;
        while(right < s.length()){
            while(charSet.find(s[right]) != charSet.end()){
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
