class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for(char c : s){
            if(!open.empty() && c == ']'){
                if(open.top() != '['){
                    return false;
                }
                open.pop();    
            }
            else if(!open.empty() && c == '}'){
                if(open.top() != '{'){
                    return false;
                }
                open.pop();
            }
            else if(!open.empty() && c == ')'){
                if(open.top() != '('){
                    return false;
                }    
                open.pop();
            }
            else if(c == '{' || c == '[' || c == '('){
                open.push(c);
            }
            else{
                return false;
            }
        }
        return open.empty();
    }
};