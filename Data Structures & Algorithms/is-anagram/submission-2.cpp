class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        vector<int> m1(26,0);
        for(int i =0; i < s.length(); i++){
            m1[s[i] - 'a']++;
            m1[t[i] - 'a']--;
        }
        for(int i : m1){
            if(i != 0){
                return false;
            }
        }
        return true;
    }
};
