class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;  // Edge case

        int occurence = -1;
        int i = 0;

        while (i <= haystack.size() - needle.size()) {  // Ensure room for full match
            if (haystack[i] == needle[0]) {
                int j = 1;
                occurence = i;
                int k = i + 1;

                while (j < needle.size() && haystack[k] == needle[j]) {
                    k++;
                    j++;
                }

                if (j == needle.size()) {
                    return occurence;
                } else {
                    occurence = -1;
                }
            }
            i++;
        }

        return -1;
    }
};
