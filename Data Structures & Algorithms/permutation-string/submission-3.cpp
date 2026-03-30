class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;  // important check

        int left = 0;
        while (left <= s2.size() - s1.size()) {  // loop over valid window positions
            string s = s2.substr(left, s1.size());
            string s1_sorted = s1;
            string s_sorted = s;
            sort(s1_sorted.begin(), s1_sorted.end());
            sort(s_sorted.begin(), s_sorted.end());
            if (s1_sorted == s_sorted) return true;  // found a permutation
            left++;
        }
        return false;
    }
};
