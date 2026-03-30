class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck;
        for(const string& s : tokens){
            if(s != "+" && s != "-" && s != "*" && s != "/"){
                stck.push(stoi(s));
            }
            else{
                int a = stck.top(); stck.pop();
                int b = stck.top(); stck.pop();
                if(s == "+") stck.push(b + a);
                if(s == "*") stck.push(b * a);
                if(s == "-") stck.push(b - a);
                if(s == "/") { if(a != 0) stck.push(b / a);}
            }
        }
        return stck.top();
    }
};
