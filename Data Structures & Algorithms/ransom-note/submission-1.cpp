class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freqRansom(26,0);
        vector<int> freqMagazine(26,0);
        for(char c : ransomNote){
            freqRansom[c - 'a']++;
        }
        for(char c : magazine){
            freqMagazine[c - 'a']++;
        }
        for(char c : ransomNote){
            if(freqRansom[c - 'a'] > freqMagazine[c-'a']){
                return false;
            }
        }
        return true;
    }
};