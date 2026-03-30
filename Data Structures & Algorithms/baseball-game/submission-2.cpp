class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> records;
        for(string& s : operations){
            char c = s[0];
            if(c != '+' && c != 'C' && c != 'D'){
                records.push(stoi(s));
            }
            else if(c == '+'){
                int a = records.top(); records.pop();
                int b = records.top();
                records.push(a);
                records.push(a + b);
            }
            else if(c == 'C'){
                records.pop();
            }
            else if(c == 'D'){
                records.push(2 * records.top());
            }
        }
        int sum = 0;
        while(!records.empty()){
            sum += records.top(); records.pop();
        }
        return sum;
    }
};
