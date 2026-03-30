class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> space;
        for(int asteroid : asteroids){
            bool destroyed = false;
            while(!space.empty() && space.back() > 0 && asteroid < 0){
                if(abs(space.back()) < abs(asteroid)){
                    space.pop_back();
                    continue;
                }
                else if(abs(space.back()) == abs(asteroid)){
                    space.pop_back();
                }
                destroyed = true;
                break;
            }
            if(!destroyed) space.push_back(asteroid);
        }
        return space;
    }
};