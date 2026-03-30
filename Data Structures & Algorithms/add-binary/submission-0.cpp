class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;

        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int digitA = i >= 0 ? a[i] - '0' : 0;
            int digitB = j >= 0 ? b[j] - '0' : 0;

            int sum = digitA + digitB + carry;
            res += (sum % 2) + '0';
            carry = sum / 2;

            i--;
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};