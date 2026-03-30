class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        if (k > s2.length()) return false;
        for(int l = 0; l <= s2.length() - k; l++){
            if(isPermutation(s1, s2.substr(l, k))){
                return true;
            }
        }
        return false;
    }
    bool isPermutation(string s, string t){
        vector<int> freq(26, 0);
        for(char c : s){
            freq[c - 'a']++;
        }
        for(char c : t){
            freq[c - 'a']--;
        }
        for(int i : freq){
            if(i != 0) return false;
        }
        return true;
    }
};