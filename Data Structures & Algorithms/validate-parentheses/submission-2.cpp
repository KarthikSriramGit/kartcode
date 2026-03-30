class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for(char c:s){
            if(c == '{' || c == '[' || c == '('){
                open.push(c);
            }
            else if(c == '}'){
                if(open.empty()|| open.top()!='{'){
                    return false;
                }
                else{
                    open.pop();
                }
            }
            else if(c == ']'){
                if(open.empty()||open.top()!='['){
                    return false;
                }
                else{
                    open.pop();
                }
            }
            else if(c == ')'){
                if(open.empty()||open.top()!='('){
                    return false;
                }
                else{
                    open.pop();
                }
            }
        }
        if(!open.empty()){
            return false;
        }
        return true;
    }
};
