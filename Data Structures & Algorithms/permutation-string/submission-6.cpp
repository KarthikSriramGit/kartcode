class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int left = 0;
        int right = s1.size() - 1;
        while(right < s2.size()){
            string curr = s2.substr(left, s1.size());
            if(isPermutation(curr, s1)){
                return true;
            }
            left++;
            right++;
        }
        return false;
    }
    bool isPermutation(string s1, string s2){
        int counts[26] = {0};
        for(char c : s1) counts[c - 'a']++;
        for(char c : s2) counts[c - 'a']--;
        for(int i = 0; i < 26; i++) {
            if(counts[i] != 0) return false;
        }
        return true;
    }
};
