class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                open.push(c);
            }
            if(c == ')'){
                if(open.empty() || open.top() != '('){
                    return false;
                }
                open.pop();
            }
            if(c == ']'){
                if(open.empty() || open.top() != '['){
                    return false;
                }
                open.pop();
            }
            if(c == '}'){
                if(open.empty() || open.top() != '{'){
                    return false;
                }
                open.pop();
            }
        }
        return open.empty();
    }
};
