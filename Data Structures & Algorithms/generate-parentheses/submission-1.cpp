class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0,0,n,res,stack);
        return res;
    }
    void backtrack(int openN, int closedN, int n, vector<string>& res, string & stack){
        // Step 1. Base case
        if(openN == closedN && openN == n){
            res.push_back(stack);
            return;
        }

        if(openN < n){ // condition
            stack += '('; // operation
            backtrack(openN + 1, closedN, n,res, stack); // try base case
            stack.pop_back(); // backtrack
        }
        if(closedN < openN){
            stack += ')';
            backtrack(openN, closedN + 1, n, res, stack);
            stack.pop_back();
        }
    }
};
