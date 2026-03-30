class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> anagrams;

        for (const string& s : strs) {
            vector<int> freq(26, 0);  // character count
            for (char c : s) {
                freq[c - 'a']++;
            }
            anagrams[freq].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : anagrams) {
            result.push_back(entry.second);
        }

        return result;
    }
};