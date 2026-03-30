class Solution {
public:
    string addBinary(string a, string b) {
        int p1 = a.length() - 1;
        int p2 = b.length() - 1;
        int sum = 0;
        string res = "";
        while(p1 >= 0 || p2 >=0 || sum){
            if(p1 >= 0) {sum += a[p1] - '0'; p1--;}
            if(p2 >= 0) {sum += b[p2] - '0'; p2--;}
            res += (sum % 2) + '0';
            sum /= 2;
        } 
        reverse(res.begin(), res.end());
        return res;
    }
};