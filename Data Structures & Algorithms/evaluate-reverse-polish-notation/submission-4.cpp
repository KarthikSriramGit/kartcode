class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> polish;
        for(string s : tokens){
            if(s == "+"){
                int a = polish.top(); polish.pop();
                int b = polish.top(); polish.pop();
                polish.push(b + a);
            }
            else if(s == "*"){
                int a = polish.top(); polish.pop();
                int b = polish.top(); polish.pop();
                polish.push(b * a);
            }
            else if(s == "-"){
                int a = polish.top(); polish.pop();
                int b = polish.top(); polish.pop();
                polish.push(b - a);
            }
            else if(s == "/"){
                int a = polish.top(); polish.pop();
                int b = polish.top(); polish.pop();
                if(a != 0) polish.push(b / a);
            }
            else{
                polish.push(stoi(s));
            }
        }
        return polish.top();
    }
};
