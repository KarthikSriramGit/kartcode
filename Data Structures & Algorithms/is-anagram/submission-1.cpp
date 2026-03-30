class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        for(char c : s){
            m1[c - 'a']++;
        }
        for(char c : t){
            m2[c - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(m1[i] != m2[i]){
                return false;
            }
        }
        return true;
    }
};
