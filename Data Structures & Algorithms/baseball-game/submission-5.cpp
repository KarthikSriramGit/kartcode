class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> score;
        for(string s : operations){
            if((s[0] >= '0' &&  s[0] <= '9') || s.size() > 1){
                score.push(stoi(s));
            }
            else if(s[0] == '+' || s[0] == 'D'){
                int first = score.top(); score.pop();
                if(s[0] == '+') {
                    int second = score.top();
                    score.push(first);
                    score.push(first + second);
                } else {
                    score.push(first);
                    score.push(2 * first);
                }
            }
            else if(s[0] == 'C'){
                score.pop();
            }
        }
        int res = 0;
        while(!score.empty()){
            res += score.top(); score.pop();
        }
        return res;
    }
};