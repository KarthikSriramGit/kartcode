class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stck;
        for(int num : asteroids){
            bool destroyed = false;
            while(!stck.empty() && isOpposite(num, stck.top())){
                if(abs(num) > abs(stck.top())){
                    stck.pop();
                }
                else if(abs(num) == abs(stck.top())){
                    stck.pop();
                    destroyed = true;
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                stck.push(num);
            }
        }
        vector<int> res;
        while(!stck.empty()){
            res.push_back(stck.top()); stck.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool isOpposite(int a, int b){
        return (a < 0 && b > 0);
    }
};
