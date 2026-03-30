class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int left = 0;
        for(int right = 0; right <= s2.length() - s1.length(); right++){
            string currString = s2.substr(left, s1.length());
            if(isPermutation(currString, s1)){
                return true;
            }
            left++;
        }
        return false;
    }
    bool isPermutation(string s1, string s2){
        vector<int> charCount(26,0);
        for(char c : s1){
            charCount[c - 'a']++;
        }
        for(char c : s2){
            charCount[c - 'a']--;
        }
        for(int num : charCount){
            if(num != 0){
                return false;
            }
        }
        return true;
    }
};
