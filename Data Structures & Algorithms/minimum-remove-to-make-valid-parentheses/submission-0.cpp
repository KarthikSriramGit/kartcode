class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> openIndices;
        unordered_set<int> toRemove;

        // First pass: track invalid ')' and unmatched '('
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                openIndices.push(i);
            } else if (s[i] == ')') {
                if (!openIndices.empty()) {
                    openIndices.pop();  // matched
                } else {
                    toRemove.insert(i); // unmatched ')'
                }
            }
        }

        // Any leftover '(' indices are unmatched
        while (!openIndices.empty()) {
            toRemove.insert(openIndices.top());
            openIndices.pop();
        }

        // Build result without indices in `toRemove`
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (toRemove.find(i) == toRemove.end()) {
                result += s[i];
            }
        }

        return result;
    }
};
