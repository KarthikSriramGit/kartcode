class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stck;
        for(int i = 0; i < s.length(); i++){
            if(!stck.empty() && s[i] == stck.top().first){
                stck.top().second++;
                if(stck.top().second == k) {
                    stck.pop();
                }
            }
            else{
                stck.push({s[i], 1});
            }
        }
        string res = "";
        while(!stck.empty()){
            res += string(stck.top().second, stck.top().first);
            stck.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};