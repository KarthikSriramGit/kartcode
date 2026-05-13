class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> charS{};
        array<int, 26> charT{}; 
        for(const char c : s){
            charS[c - 'a']++;
        }
        for(const char c : t){
            charT[c - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(charS[i] != charT[i]){
                return false;
            }
        }
        return true;
    }
};
