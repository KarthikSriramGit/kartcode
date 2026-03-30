class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_set<int> seen;
        int maxlen = 0;
        while(right < s.length()){
            if(seen.find(s[right]) != seen.end()){
                seen.erase(s[left]);
                left++;
            }
            else{
                seen.insert(s[right]);
                maxlen = max(maxlen, right - left + 1);
                right++;
            }
        }
        return maxlen;
    }
};
