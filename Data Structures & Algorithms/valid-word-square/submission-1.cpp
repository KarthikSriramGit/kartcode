class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        vector<string> cmp;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                if(j >= words.size() || i >= words[j].length() || words[i][j] != words[j][i]){
                    return false;
                }
            }
        }
        return true;
    }
};
