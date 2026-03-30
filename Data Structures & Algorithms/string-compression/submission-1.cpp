class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0;
        int right = 0;
        string s = "";
        while(right < chars.size()){
            if(right + 1 == chars.size() || chars[right + 1] != chars[left]){
                s += chars[right];
                int count = right - left + 1;
                if(count > 1){
                    string co = to_string(count);
                    for(char c : co) {
                        s += c;
                    }
                }
                left = right + 1;
            }
            right++;
        }
        for (int i = 0; i < s.size(); i++) {
            chars[i] = s[i];
        }
        return s.size();
    }
};