class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0;
        int maxlen = 0;
        unordered_map<char, int> freq;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);
            while((right - left + 1) - maxFreq > k){
                freq[s[left]]--;
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};
