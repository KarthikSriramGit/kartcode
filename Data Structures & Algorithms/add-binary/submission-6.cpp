class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = 0;
        int p1 = a.length() - 1;
        int p2 = b.length() - 1;
        string res = "";
        while(p1 >= 0 || p2 >= 0){
            char charA = (p1 >= 0) ? a[p1] : '0';
            char charB = (p2 >= 0) ? b[p2] : '0';
            if(charA == '0' && charB == '0'){
                if(carry == false){ 
                    res += "0";
                }
                else{
                    res += "1";
                    carry = false;
                }
            }
            else if((charA == '0' && charB == '1') || (charA == '1' && charB == '0') ){
                if(carry == false){ 
                    res += "1";
                }
                else{
                    res += "0";
                }
            }
            else{
                if(carry == false){
                    res += "0";
                }
                else{
                    res += "1";
                }
                carry = true;
            }
            p1--;
            p2--;
        }
        if(carry){
            res += "1";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};