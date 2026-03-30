class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int minlen = INT_MAX;
        string result = "";
        while(right < s.size()){
            while(right < s.size() && !isValid(s.substr(left, right - left + 1), t)){
                right++;
            }
            while(left <= right && isValid(s.substr(left, right - left + 1), t)){
                if(right - left + 1 < minlen){
                    minlen = right - left + 1;
                    result = s.substr(left, right - left + 1);
                }
                left++;
            }
            right++;
        }   
        return result;
    }
    bool isValid(string s1, string s2){
        unordered_map<char, int> f1;
        unordered_map<char, int> f2;
        for(char c : s1){
            f1[c]++;
        }
        for(char c : s2){
            f2[c]++;
        }
        for(auto& iter : f2){
            if(iter.second > 0 && iter.second > f1[iter.first]){
                return false;
            }
        }
        return true;
    }
};