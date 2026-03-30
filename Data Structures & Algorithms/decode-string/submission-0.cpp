class Solution {
public:
    string decodeString(string s) {
        vector<string> stck;
        string k = "";
        for(char c : s){
            if(isdigit(c)) {
                k += c;
            } 
            else if(c == '[') {
                if(!k.empty()) { stck.push_back(k); k = ""; }
                stck.push_back("[");
            } 
            else if(c == ']') {
                string curr = "";
                while(stck.back() != "["){
                    curr = stck.back() + curr;
                    stck.pop_back();
                }
                stck.pop_back();
                int num = stoi(stck.back()); stck.pop_back();
                string repeated = "";
                for(int i = 0; i < num; i++){
                    repeated += curr;
                }
                stck.push_back(repeated);
            } 
            else {
                stck.push_back(string(1, c));
            }
        }
        string res = "";
        for(string str : stck) res += str;
        return res;
    }
};