class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(const string& str : strs){
            encoded += to_string(str.length()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;
        while(i < s.length()){
            int delimiter = s.find("#", i);
            int len = stoi(s.substr(i, delimiter - i));
            res.push_back(s.substr(delimiter+1, len));
            i = delimiter +  1 + len;
        }        
        return res;
    }
};
