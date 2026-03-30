class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0;
        int right = 0;
        int write = 0;
        while(right < chars.size()){
            if(right + 1 == chars.size() || chars[right + 1] != chars[left]){
                chars[write++] = chars[left];
                int count = right - left + 1;
                if(count > 1){
                    string s = to_string(count);
                    for(char c : s) {
                        chars[write++] = c;
                    }
                }
                left = right + 1;
            }
            right++;
        }
        return write;
    }
};