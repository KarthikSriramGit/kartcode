class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int longest = 0;
        unordered_set<char> seen;
        while(right < s.size()){
            while(seen.find(s[right])!=seen.end()){
                seen.erase(s[left]);
                left++;
            }
            longest = max(longest, right - left +1);
            seen.insert(s[right]);
            right++;
        }
        return longest;
    }
};
