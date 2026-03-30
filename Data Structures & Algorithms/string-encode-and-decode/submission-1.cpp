class Solution {
public:
    string encode(const vector<string>& strs) {
        string encoded;
        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(const string& s) {
        vector<string> result;
        size_t i = 0;

        while (i < s.size()) {
            // Find the delimiter #
            size_t delimiter = s.find('#', i);
            int len = stoi(s.substr(i, delimiter - i));
            result.push_back(s.substr(delimiter + 1, len));
            i = delimiter + 1 + len;
        }

        return result;
    }
};