class Solution {
public:
    int lengthOfLongestSubstring(string s){
	unordered_set<char> window;
	int left = 0;
	int right = 0;
	int maxW = 0;
    while(right < s.length()){
            if(window.find(s[right]) != window.end()){
                window.erase(s[left]);
                left++;
            }
            else{
                window.insert(s[right]);
                right++;
                maxW = max(maxW, (int)window.size());
            }
        }
        return maxW;
    }
};