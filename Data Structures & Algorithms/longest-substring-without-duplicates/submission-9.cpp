class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxlen = 0;
        unordered_set<char> seen;
        for(int right = 0; right < s.length(); right++){
            while(seen.find(s[right]) != seen.end()){
                seen.erase(s[left]);
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
            seen.insert(s[right]);
        }
        return maxlen;
    }
};
