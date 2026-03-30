class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int time = 0;
        int currentPos = 0;
        for(int p = 0; p < word.size(); p++){
            int nextPos = keyboard.find(word[p], 0);
            time += abs(nextPos - currentPos);
            currentPos = nextPos;
        }
        return time;
    }
};