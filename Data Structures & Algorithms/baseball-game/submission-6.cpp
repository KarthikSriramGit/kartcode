class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for(string s : operations){
            if(s == "+"){
                int a = scores.top(); scores.pop();
                int b = scores.top(); scores.pop();
                scores.push(b);
                scores.push(a);
                scores.push(a + b);
            }
            else if(s == "C") scores.pop();
            else if(s == "D") scores.push(2 * scores.top());
            else scores.push(stoi(s));
        }
        int sum = 0;
        while(!scores.empty()){
            sum += scores.top(); scores.pop();
        }
        return sum;
    }
};