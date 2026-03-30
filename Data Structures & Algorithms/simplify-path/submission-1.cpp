class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        path += '/';
        string current = "";
        for(char c : path){
            if(c == '/'){
                if(current == ".."){
                    if(!dirs.empty()) dirs.pop_back();
                }
                else if(current != "." && current != ""){
                    dirs.push_back(current);
                }
                current = "";
            }
            else{
                current += c;
            }
        }
        string result = "";
        for(string dir : dirs){
            result += "/" + dir;            
        }
        return result.empty() ? "/" : result;    }
};