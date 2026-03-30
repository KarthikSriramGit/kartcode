class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ns = s.length(), nt = t.length();
        if (ns > nt) return isOneEditDistance(t, s);
        if (nt - ns > 1) return false;

        for (int i = 0; i < ns; i++) {
            if (s[i] != t[i]) {
                if (ns == nt) {
                    return s.substr(i + 1) == t.substr(i + 1);
                } else {
                    return s.substr(i) == t.substr(i + 1);
                }
            }
        }
        return ns + 1 == nt;
    }
};