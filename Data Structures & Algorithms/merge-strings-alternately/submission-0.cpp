class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int left = 0;
        int right = word1.size() >= word2.size()? word2.size():word1.size();
        string merged;
        while(left < right){
            merged += word1[left];
            merged += word2[left];
            left++;
        }
        if(word1.size() > word2.size()){
            while(left < word1.size()){
                merged += word1[left];
                left++;
            }
        }
        else if(word2.size() > word1.size()){
            while(left < word2.size()){
                merged += word2[left];
                left++;
            }
        }
        return merged;
    }
};