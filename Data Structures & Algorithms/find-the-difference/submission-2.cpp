class Solution {
public:
    char findTheDifference(string s, string t) {
        char xorr = 0;
        for(char c : s){
            xorr ^= c;
        }
        for(char c : t){
            xorr ^= c;
        }
        return (char)xorr;
    }
};