class Solution {
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        vector<int> stack;
        int num = 0;
        char op = '+';
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            if (!isdigit(ch) || i == s.size() - 1) {
                if (op == '+') {
                    stack.push_back(num);
                } else if (op == '-') {
                    stack.push_back(-num);
                } else if (op == '*') {
                    int prev = stack.back(); stack.pop_back();
                    stack.push_back(prev * num);
                } else {
                    int prev = stack.back(); stack.pop_back();
                    stack.push_back(prev / num);
                }
                op = ch;
                num = 0;
            }
        }
        int res = 0;
        for (int x : stack) res += x;
        return res;
    }
};